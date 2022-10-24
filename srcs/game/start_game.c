#include "cub3d.h"
#include <math.h>
#include <oslib.h>

# define V_WALL_RGB	0xff7F3335
# define H_WALL_RGB 0xff99585C

static void	__move(t_self *self, float x, float y)
{
	if (self->map.data
		[(int)(self->player.pos.y + y)]
		[(int)(self->player.pos.x + x)] != '1')
	{
		self->player.pos.x += x;
		self->player.pos.y += y;
	}
}

typedef struct s_vert
{
	unsigned long color;
	short x, y, z;
} t_vert;

void drawline(int x0, int y0, int x1, int y1, OSL_COLOR color)		{
		t_vert*	vertices;

		vertices = sceGuGetMemory(2 * sizeof(t_vert));

		vertices[0].color = color;
		vertices[0].x = x0;
		vertices[0].y = y0;
		vertices[0].z = 0;

		vertices[1].color = color;
		vertices[1].x = x1;
		vertices[1].y = y1;
		vertices[1].z = 0;

		sceGuDisable(GU_TEXTURE_2D);
		sceGuDrawArray(
			GU_LINES,
			GU_COLOR_8888
				| GU_VERTEX_16BIT
				| GU_TRANSFORM_2D,
				2,
				NULL,
				vertices);
		sceGuEnable(GU_TEXTURE_2D);
}

void peek_keys(t_self *self)
{
	int speed;

	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(1);
    sceCtrlPeekBufferPositive(&self->pad, 1);

	if (self->pad.Buttons & PSP_CTRL_CROSS)
		speed = SPEED / 2;
	else
		speed = SPEED;
	if (self->pad.Buttons & PSP_CTRL_DOWN)
		__move(self,
            -cosf(self->player.angle) / speed,
            -sinf(self->player.angle) / speed);
	if (self->pad.Buttons & PSP_CTRL_UP)
	    __move(self,
            cosf(self->player.angle) / speed,
            sinf(self->player.angle) / speed);
	if (self->pad.Buttons & PSP_CTRL_LEFT)
	    __move(self,
            cosf(self->player.angle - 1.5708) / speed,
            sinf(self->player.angle - 1.5708) / speed);
	if (self->pad.Buttons & PSP_CTRL_RIGHT)
	    __move(self,
            cosf(self->player.angle + 1.5708) / speed,
            sinf(self->player.angle + 1.5708) / speed);
	if (self->pad.Buttons & PSP_CTRL_RTRIGGER)
		self->player.angle += SENSITIVITY;
	if (self->pad.Buttons & PSP_CTRL_LTRIGGER)
		self->player.angle -= SENSITIVITY;
}

void	raycast(t_self *self)
{
	int		side = 0;
	float	line_len;
	float	current_angle;
	int		i;
	struct	s_ray {
		ScePspFVector2	pos;
		ScePspFVector2	dir;
		ScePspFVector2	delta;
		ScePspFVector2	len;
		ScePspIVector2	map;	
		ScePspIVector2	step;
	}	r;
	
	current_angle = self->player.angle - (FOV / 2);
	r.pos.x       = self->player.pos.x;
	r.pos.y       = self->player.pos.y;

	for (i = 0; i < SCR_X; i++)
	{
		current_angle += FOV / SCR_X;
		r.dir.x        = cosf(current_angle);
		r.dir.y        = sinf(current_angle);
		r.delta.x      = fabs(1 / r.dir.x);
		r.delta.y      = fabs(1 / r.dir.y);
		r.map.x        = (int)r.pos.x;
		r.map.y        = (int)r.pos.y;

		if (r.dir.x < 0) {
        	r.step.x = -1;
        	r.len.x = (r.pos.x - r.map.x) * r.delta.x;
      	} else {
       		r.step.x = 1;
        	r.len.x = (r.map.x + 1.0 - r.pos.x) * r.delta.x;
      	}
		if (r.dir.y < 0) {
        	r.step.y = -1;
        	r.len.y = (r.pos.y - r.map.y) * r.delta.y;
      	} else {
       		r.step.y = 1;
        	r.len.y = (r.map.y + 1.0 - r.pos.y) * r.delta.y;
      	}

		while (r.map.x >= 0 && r.map.x <= self->map.max_x 
			&& r.map.y >= 0 && r.map.y <= self->map.max_y
			&& self->map.data[r.map.y][r.map.x] != '1')
    	{
        	if (r.len.x < r.len.y)
        	{
          		r.len.x += r.delta.x;
          		r.map.x += r.step.x;
          		side = 0;
			}
        	else
        	{
          		r.len.y += r.delta.y;
          		r.map.y += r.step.y;
          		side = 1;
			}
    	}

		if (side == 0)
			line_len = SCR_Y / (r.len.x - r.delta.x)
				/ cosf(current_angle - self->player.angle);
		else
			line_len = SCR_Y / (r.len.y - r.delta.y)
				/ cosf(current_angle - self->player.angle);		

		drawline(
			i, -line_len / 2 + SCR_Y / 2, 
			i, line_len / 2 + SCR_Y / 2,
			side == 0 ?
				0xff35337f : 0xff5c5899);
	}
}

void	start_game(t_self *self)
{
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);

	while (!osl_quit)
	{
		peek_keys(self);
		oslStartDrawing();
		sceGuClearColor(0xff0000ff);
		sceGuClear(GU_COLOR_BUFFER_BIT);
		oslDrawFillRect(0, 0, SCR_X, SCR_Y / 2, 0xffe0cdb3);
		oslDrawFillRect(0, SCR_Y / 2, SCR_X, SCR_Y, 0xffb19764); 
		raycast(self);
		drawline(
			SCR_X / 2, SCR_Y / 2 - 6, 
			SCR_X / 2, SCR_Y / 2 + 7,
			self->pad.Buttons & PSP_CTRL_CIRCLE ?
				0xff0000ff : 0xffffffff);
		drawline(
			SCR_X / 2 - 6, SCR_Y / 2,
			SCR_X  / 2 + 7, SCR_Y / 2,
			self->pad.Buttons & PSP_CTRL_CIRCLE ?
				0xff0000ff : 0xffffffff);	
		oslEndDrawing();
		oslSyncFrame();
	}
	oslEndGfx();
	oslQuit();
}