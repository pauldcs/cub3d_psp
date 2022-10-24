#ifndef MAP_H
# define MAP_H

# define SPACE_RGB   0x828282
# define BG_RGB      0x3a3a3a
# define GUIDES_RGB  0x9A1818
# define V_WALL_RGB  0x7F3335
# define H_WALL_RGB  0x99585C

# define MAP_X  91
# define MAP_Y  25

const char *c3d_map[] = {
	"1111111111111111    11111111111111111111111111111111111111111111111111111111111111111      ",
	"1000000000000001    100000000000000000000000000000000000000000000000000000000000000011     ",
	"1000000000000001    1000111111111111110000000111111111100000000000000000000000000000011    ",
	"1000000000000001    10001            100000001        1000111111111111111000000111100011   ",
	"1000000000000001111100001            100000001        10001            10000001    100011  ",
	"1000000000000000000000001            100000001        10001           10000001      100011 ",
	"1000000000000000000000001    11111111100000001        10001          10000001        100011",
	"1000000000000000000000001111110000000000000001        10001         10000001        100011 ",
	"11111000111111111100000000000000000000000000011111111110001        10000001        100011  ",
	"    11111        100001111111100000000000000000000000000001111111110000001        100011   ",
	"                 100001      10000000111111000000000000000000000000000001        100011    ",
	"                 100001      100000001    10000000000000000000000000000111111111100011     ",
	"      1111111111110000011    100000001    1111111111111111111111000000000000000000011      ",
	"      1000000000000000001    100010001                         100011111111111100011       ",
	"      1000000000000000001    100010001                         1001          100011        ",
	"1111111111111100000000001111110001000111111111111111111111111111001         100011         ",
	"1000000000000000000000000000000001000000000000000000000000000000001        100011          ",
	"10000000000000000000000011111111111111111111111111111111111111100001      100011           ",
	"1000000000000000000000001                                    10011001    100011            ",
	"11111000000000000000000011111                               1001  1001  100011             ",
	"    1000000001111111100000001                              1001    1001100011              ",
	"11111000000001      10000000111111111111111111111111111111100001111000000011               ",
	"1000000X000001      1000000000000000000000000000000000000000000000000000011                ",
	"10000000000001      100000000000000000000000000000000000000000000000000011                 ",
	"11111111111111      11111111111111111111111111111111111111111111111111111                  "};

#endif 