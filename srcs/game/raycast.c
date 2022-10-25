#include "cub3d.h"
#include "psp/psptypes.h"
#include <math.h>

void	raycast(t_self *self)
{
	int		osc = 256;
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
		r.dir.x = cosf(current_angle);
		r.dir.y = sinf(current_angle);
		r.delta.x = fabs(1 / r.dir.x);
		r.delta.y = fabs(1 / r.dir.y);
		r.map.x = (int)r.pos.x;
		r.map.y = (int)r.pos.y;

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

		osc+=1;
		draw_line(
			i, -line_len / 2 + SCR_Y / 2, 
			i, line_len / 2 + SCR_Y / 2,
			side == 0 ? 0xff35337f : 0xff5c5899);
	}
}