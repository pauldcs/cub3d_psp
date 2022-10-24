#include "cub3d.h"
#include <math.h>
#include <oslib.h>

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

void peek_keys(t_self *self)
{
	oslReadKeys();

	if (osl_keys->pressed.down)
		__move(self,
            -cosf(self->player.angle) / SPEED,
            -sinf(self->player.angle) / SPEED);
	if (osl_keys->pressed.up)
	    __move(self,
            cosf(self->player.angle) / SPEED,
            sinf(self->player.angle) / SPEED);
	if (osl_keys->pressed.left)
	    __move(self,
            cosf(self->player.angle - 1.5708) / SPEED,
            sinf(self->player.angle - 1.5708) / SPEED);
	if (osl_keys->pressed.right)
	    __move(self,
            cosf(self->player.angle + 1.5708) / SPEED,
            sinf(self->player.angle + 1.5708) / SPEED);
	if (osl_keys->pressed.L)
		self->player.angle += SENSITIVITY;
	if (osl_keys->pressed.R)
		self->player.angle -= SENSITIVITY;
}

void	start_game(t_self *self)
{
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
	oslInitConsole();

	oslSetKeyAutorepeatInit(40);
	oslSetKeyAutorepeatInterval(10);
	while (!osl_quit)
	{
		oslStartDrawing();
		peek_keys(self);
		//oslPrintf("x: %f, y: %f\n", self->player.pos.x, self->player.pos.y);
		oslDrawLine(
			0, 0,
			100, 100,
			RGBA(100,0,0,255));
		oslEndDrawing();
		oslSyncFrame();
	}
	oslEndGfx();
	oslQuit();
}