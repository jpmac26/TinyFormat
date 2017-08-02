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
    gfxInitDefault(); //makes displaying to screen easier
    
    aptInit();
    fsInit();
    //hidInit();

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
            printf("ALL YOUR DATA WILL BE DELETED (except on SD Card)!\n");
            printf("Press Y again to format your system, or START to exit.\n");
            if (hidKeysDown() & KEY_START)
            {
                printf("CANCELED! Exiting...\n");
                break;
            }
            else if (hidKeysDown() & KEY_Y)
            { 
                printf("Running InitializeCtrFileSystem. Please wait...\n");
                //fsUseSession(fsGetSessionHandle());
                res = FSUSER_InitializeCtrFileSystem();
                //fsEndUseSession();
                
                if (res == 0)
                    printf("Done!\n");
                else
                    printf("FAILED!\n");

                printf("Waiting for system reboot...\n");
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
    //hidExit();
    fsExit();
    aptExit();
    gfxExit();
    return 0;
}
