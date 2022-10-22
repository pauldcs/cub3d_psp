PSP_EBOOT_TITLE := cub3D_PSP
PSP_EBOOT_ICON  := other/redtiger.jpg
TARGET          := $(PSP_EBOOT_TITLE)
EXTRA_TARGETS   := EBOOT.PBP
OBJS            :=          \
	srcs/main.o             \
	srcs/common/callbacks.o \
	srcs/common/vram.o      \
	srcs/do_moving.c        \

INCDIR    := incs
CFLAGS    := -g3 -Wall -Wextra -O3
CXXFLAGS  := $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS   := $(CFLAGS)
LIBS      := -lpspgum -lpspgu -lm

#LIBDIR    :=
#LDFLAGS   :=

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
