#include "psp/pspkernel.h"
#include "psp/pspdebug.h"
#include "psp/pspctrl.h"
#include "common/callbacks.h"
#include "cub3d.h"
#include <stdlib.h>
#include <string.h>

PSP_MODULE_INFO("CUB3D_PSP", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_THRESHOLD_SIZE_KB(0);

static void game(t_self *self)
{
    SceCtrlData pad;

    pspDebugScreenInit();
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
    while (running())
    {
        sceCtrlReadBufferPositive(&pad, 1);
        peek_pad(self, &pad);
    }
}

int main (int ac, char *av[])
{
    t_self  self;
    
    (void)ac;
    (void)av;
    memset(&self, 0, sizeof(t_self));
	setup_call_backs();
    game(&self);
    return (EXIT_SUCCESS);
}