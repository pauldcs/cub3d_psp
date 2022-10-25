#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include "psp/psptypes.h"
# include "psp/pspctrl.h"

# define SCR_X           480
# define SCR_Y           272
# define SENSITIVITY    0.04
# define SPEED            16
# define FOV        1.047198
# define MAP_X            91
# define MAP_Y            25

typedef struct s_map {
    u8   **data;
    u64  max_x;
    u64  max_y;
}   t_map;

typedef struct s_self {
    SceCtrlData pad;
    struct      s_player {
        ScePspFVector2  pos;
        float           angle;
        int             health;
        int             stamina;
    }   player;
    t_map   map;
}   t_self;

void	start_game(t_self *self);
void	raycast(t_self *self);
void    peek_keys(t_self *self);
void    draw_line(int x0, int y0, int x1, int y1, int c);

#endif