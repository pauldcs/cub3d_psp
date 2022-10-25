#include "psp/pspctrl.h"
#include "cub3d.h"
#include <math.h>

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
	int speed;

	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(1);
    sceCtrlPeekBufferPositive(&self->pad, 1);

	if (self->pad.Buttons & PSP_CTRL_CROSS)
	{
		if (self->player.stamina <= 0)
			return ;
		self->player.stamina--;
		speed = SPEED / 2;
	} else {
		if (self->player.stamina < 100)
			self->player.stamina++;
		speed = SPEED;
	}
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