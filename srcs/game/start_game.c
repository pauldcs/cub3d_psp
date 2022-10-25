#include "cub3d.h"
#include <math.h>
#include <oslib.h>

static void	main_game(t_self *self)
{
	peek_keys(self);
	oslStartDrawing();
	sceGuClearColor(0xff000000);
	sceGuClear(GU_COLOR_BUFFER_BIT);
	oslDrawFillRect(
		0, 0,
		SCR_X, SCR_Y / 2,
		0xffc39b8d);
	oslDrawFillRect(
		0, SCR_Y / 2,
		SCR_X, SCR_Y,
		0xff2f3034); 
	raycast(self);
	oslDrawStringf(5, 5,  "health  %3d%%", self->player.health);
	oslDrawStringf(5, 17, "stamina %3d%%", self->player.stamina);
	draw_line(
		SCR_X / 2, SCR_Y / 2 - 6, 
		SCR_X / 2, SCR_Y / 2 + 7,
		self->pad.Buttons & PSP_CTRL_CIRCLE ? 0xff0000ff : 0xffffffff);
	draw_line(
		SCR_X / 2 - 6, SCR_Y / 2,
		SCR_X  / 2 + 7, SCR_Y / 2,
		self->pad.Buttons & PSP_CTRL_CIRCLE ? 0xff0000ff : 0xffffffff);	
	oslEndDrawing();
	oslSyncFrame();
}

void	start_game(t_self *self)
{
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);

	while (!osl_quit)
		main_game(self);
	oslEndGfx();
	oslQuit();
}