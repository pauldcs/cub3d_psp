#ifndef KEYS_H
# define KEYS_H

# include "psp/psptypes.h"

# define KEY_SELECT      0x1
# define KEY_START       0x2
# define KEY_UP          0x4
# define KEY_RIGHT       0x8
# define KEY_DOWN       0x10
# define KEY_LEFT       0x20
# define KEY_L          0x40
# define KEY_R          0x80
# define KEY_TRIANGLE  0x100
# define KEY_CIRCLE    0x200
# define KEY_CROSS     0x400
# define KEY_SQUARE    0x800

typedef struct s_keys {
    u32 pressed;
    u32 held;
    u32 released;
    struct s_stick {
        s8  x;  // -128: left, +127: right
        s8  y;  // -128: left, +127: right
    }   t_stick;
}   t_keys;

#endif