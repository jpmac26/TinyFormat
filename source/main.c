/*
 * TinyFormat v1.1
 * javiMaD & CaptainSwag101
 */

#include <stdio.h>
#include <string.h>
#include <3ds.h>
#include <3ds/services/apt.h>
#include <3ds/services/fs.h>
#include <3ds/services/hid.h>
#include <3ds/srv.h>


int main(int argc, char** argv)
{
    // Initialize services
    gfxInitDefault();
    aptInit();
    fsInit();

    bool confirming = false;
    Result res;

    // Init console for text output
    consoleInit(GFX_BOTTOM, NULL);

    printf("TinyFormat v1.1\n");
    printf("---------------\n\n");
    printf("Press Y to format.\n");
    printf("Press START to exit.\n\n");

    // Main loop
    while (aptMainLoop())
    {
        hidScanInput();

        if (hidKeysDown() & KEY_START)
        {
            printf("CANCELED! Exiting...\n");
            break;
        }
        else if (hidKeysDown() & KEY_Y)
        {
            confirming = true;
            continue;
        }
        
        if (confirming)
        {
            printf("Are you sure? ALL YOUR DATA WILL BE DELETED!\n");
            printf("Press Y again to confirm, or START to exit.\n\n");
            
            if (hidKeysDown() & KEY_START)
            {
                printf("CANCELED! Exiting...\n");
                break;
            }
            else if (hidKeysDown() & KEY_Y)
            { 
                printf("Initializing CTRNAND. Please wait...\n");
                res = FSUSER_InitializeCtrFileSystem();
                
                if (res == 0)
                    printf("Done!\n");
                else
                    printf("FAILED!\n");

                printf("The system will reboot in 3 seconds...\n");
                svcSleepThread(3000000000);
                APT_HardwareResetAsync();
            }
        }

        // Flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    // Exit services
    fsExit();
    aptExit();
    gfxExit();
    return 0;
}
