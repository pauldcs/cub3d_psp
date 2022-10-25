PSP_EBOOT_TITLE := cub3D_psp
TARGET          := $(PSP_EBOOT_TITLE)
EXTRA_TARGETS   := EBOOT.PBP
OBJS            :=          \
	srcs/main.o             \
	srcs/common/callbacks.o \
	srcs/common/vram.o      \
	srcs/game/start_game.o  \
	srcs/game/draw_line.o   \
	srcs/game/peek_keys.o   \
	srcs/game/raycast.o   \

INCDIR    := incs
CFLAGS    := -g3 -Wall -Wextra -O3
CXXFLAGS  := $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS   := $(CFLAGS)
LIBS      := -lm -lstdc++ \
			-Llib/oslib -losl \
			-lpng -ljpeg  -lz \
			-lpsphprm -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspgum  -lpspaudiolib -lpspaudio -lpsphttp -lpspssl -lpspwlan \
			-lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lpspaudio -lpspgu -lpsppower -lpsphprm

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak


