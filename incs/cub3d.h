#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include "psp/psptypes.h"
# include "psp/pspctrl.h"

# define SENSITIVITY 0.2
# define SPEED       16

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
    }   player;
    t_map   map;
}   t_self;

void	start_game(t_self *self);

#endif