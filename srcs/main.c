#include "cub3d.h"
#include "psp/pspkernel.h"
#include "map.h"
#include <stdlib.h>
#include <string.h>

PSP_MODULE_INFO("cub3D_psp", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

static void	init_self(t_self *self)
{
	memset(self, 0x00, sizeof(t_self));
    self->map.data = (u8 **)c3d_map;
    self->map.max_x = MAP_X;
    self->map.max_y = MAP_Y;
    self->player.pos.x = 3;
    self->player.pos.y = 3;
    self->player.angle = 1.570796;
    self->player.health = 100;
}

int main(void)
{
	t_self  self;

	init_self(&self);
    start_game(&self);
	return (0);
}