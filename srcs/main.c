#include "psp/pspkernel.h"
#include "psp/pspdebug.h"
#include "common/callbacks.h"
#include "common/vram.h"
#include "psp/pspgu.h"
#include "psp/pspdisplay.h"
#include "psp/pspdisplay.h"
#include "cub3d.h"
#include "map.h"
#include <stdlib.h>
#include <string.h>

#define SCREEN_X 512
#define SCREEN_Y 480

#define PSP_BUFFSIZE 512

PSP_MODULE_INFO("CUB3D_PSP", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

static unsigned int __attribute__((aligned(16))) list[262144];

static void init_graphics(void)
{
    void* fbp0 = get_static_vram_buffer(PSP_BUFFSIZE, SCREEN_Y, GU_PSM_8888);
	void* fbp1 = get_static_vram_buffer(PSP_BUFFSIZE, SCREEN_Y, GU_PSM_8888);
	void* zbp = get_static_vram_buffer(PSP_BUFFSIZE, SCREEN_Y, GU_PSM_4444);

	sceGuInit();
    sceGuStart(GU_DIRECT, list);
	sceGuDrawBuffer(
		GU_PSM_8888,
		fbp0,
		PSP_BUFFSIZE);
	sceGuDispBuffer(
		SCREEN_X,
		SCREEN_Y,
		fbp1,
		PSP_BUFFSIZE);
	sceGuDepthBuffer(zbp, PSP_BUFFSIZE);
	sceGuOffset(
		2048 - (SCREEN_X / 2),
		2048 - (SCREEN_Y / 2));
	sceGuViewport(
		2048,
		2048,
		SCREEN_X,
		SCREEN_Y);
	sceGuDepthRange(
		0xc350,
		0x2710);
	sceGuScissor(
		0,
		0,
		SCREEN_X,
		SCREEN_Y);
	sceGuEnable(GU_SCISSOR_TEST);
	sceGuAlphaFunc(
		GU_GREATER,
		0,
		0xff);
	sceGuEnable(GU_ALPHA_TEST);
	sceGuDepthFunc(GU_GEQUAL);
	sceGuEnable(GU_DEPTH_TEST);
	sceGuFrontFace(GU_CW);
	sceGuShadeModel(GU_SMOOTH);
	sceGuEnable(GU_CULL_FACE);
	sceGuEnable(GU_TEXTURE_2D);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	sceGuDisplay(GU_TRUE);
}

static void term_graphics(void)
{
    sceGuTerm();
}

static void start_frame(void)
{
	sceGuStart(GU_DIRECT, list);
}

static void end_frame(void)
{
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
}

static void handle_ctrl(t_self *self)
{
	sceCtrlReadBufferPositive(&self->pad, 1);
	if (self->pad.Buttons)
    {
        if (self->pad.Buttons & PSP_CTRL_LTRIGGER)   pspDebugScreenPrintf("L pressed\n");
        if (self->pad.Buttons & PSP_CTRL_RTRIGGER)   pspDebugScreenPrintf("R pressed\n");
        if (self->pad.Buttons & PSP_CTRL_CIRCLE)     pspDebugScreenPrintf("Circle pressed\n");
        if (self->pad.Buttons & PSP_CTRL_CROSS)      pspDebugScreenPrintf("Cross pressed\n");
        if (self->pad.Buttons & PSP_CTRL_UP)         pspDebugScreenPrintf("Up pressed\n");
        if (self->pad.Buttons & PSP_CTRL_DOWN)       pspDebugScreenPrintf("Down pressed\n");
        if (self->pad.Buttons & PSP_CTRL_LEFT)       pspDebugScreenPrintf("Left pressed\n");
        if (self->pad.Buttons & PSP_CTRL_RIGHT)      pspDebugScreenPrintf("Right pressed\n");
    }
}

int main(void)
{
    t_self  self;
    
    setup_call_backs();

    memset(&self, 0x00, sizeof(t_self));
    self.map.data = (u8 **)c3d_map;
    self.map.max_x = MAP_X;
    self.map.max_y = MAP_Y;
    self.map.scene.ceil = CEIL_RGB;
    self.map.scene.floor = FLOOR_RGB;

	init_graphics();
	pspDebugScreenInit();
	sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    while (running())
    {
		//pspDebugScreenPrintf("Hello\n");
		start_frame();
		sceGuClearColor(0xff0000);
		sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);
		end_frame();
    }
	term_graphics();
    return (0);
}