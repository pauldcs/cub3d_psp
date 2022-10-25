#include "cub3d.h"
#include <math.h>
#include <oslib.h>

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
		oslDrawFillRect(
			0, 0,
			SCR_X, SCR_Y / 2,
			0xff98593b);
		oslDrawFillRect(
			0, SCR_Y / 2,
			SCR_X, SCR_Y,
			0xffc39d8b); 
		raycast(self);
		draw_line(
			SCR_X / 2, SCR_Y / 2 - 6, 
			SCR_X / 2, SCR_Y / 2 + 7,
			self->pad.Buttons & PSP_CTRL_CIRCLE ?
				0xff0000ff : 0xffffffff);
		draw_line(
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