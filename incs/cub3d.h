#ifndef CUB3D_H
# define CUB3D_H

# include "psp/psptypes.h"
# include "psp/pspctrl.h"
# include <stdbool.h>
# include <stddef.h>

#define VERS    1 
#define REVS    1

typedef struct s_map {
    u8   **data;
    u64  max_x;
    u64  max_y;
    struct s_scene {
        u32 ceil;
        u32 floor;
    }   scene;
}   t_map;

typedef struct s_self {
    SceCtrlData pad;
    struct      s_player {
        ScePspFVector2  pos;
        float           angle;
    }   player;
    t_map   map;
}   t_self;

bool	start_game(t_self *self);

#endif