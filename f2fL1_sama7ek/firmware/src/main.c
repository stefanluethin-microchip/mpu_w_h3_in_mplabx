/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
//-SL:
volatile uint32_t myCnt;
volatile uint32_t finalLedCnt;
#define cEchoCnt 10
#define PRESSED  0
#define RELEASED 1
volatile bool genTmrExFlag;

char charArray[3] = {'x','y','z'};
volatile uint32_t char2prntIdx; //- index for 'charArray'
void testEnd(void);


void genTmr_handler(uintptr_t context)
{
	genTmrExFlag=true;
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    printf("\n\r");
    printf("\n\r START H3 on SAMA7G5 with at91=intSRAM (SLx: at91-loop_ide) ...");
    //-SL: printf("\n\r START H3 on SAMA7G5 with at91=intSRAM (SLx: at91-prod_sdcard) ...");

     //-SL: inits
    myCnt=0;
    finalLedCnt=0;
    genTmrExFlag=false;
     //-SL: userbutton defined as GPIOIn but still need to call this fct to enable on MPUs
    SW1_InputEnable();
    char2prntIdx=0; //- default char-to-print = 'b'

    GENERIC_TIMER_Start();
    GENERIC_TIMER_CallbackRegister((GENERIC_TIMER_CALLBACK)genTmr_handler, (uintptr_t) NULL);
    
    while ( true )
    {
        if(genTmrExFlag)
        {
            genTmrExFlag=false;
            finalLedCnt++;
        
            myCnt++;
            if(cEchoCnt/2>=myCnt)
            {
                LEDBLUE_Toggle();
                printf("w");
            } else if ((cEchoCnt/2<myCnt) & (cEchoCnt>=myCnt))
            {
                LEDGREEN_Toggle();
                printf("%c",charArray[char2prntIdx]);
                if (cEchoCnt==myCnt)
                    myCnt=0;
            } else
                printf("ERROR1");
    }
        if(PRESSED == SW1_Get())
        {
            testEnd();
        }
    }
    return ( EXIT_FAILURE );
}

void testEnd(void)
{
    printf("\n\r H3 on SAMA7G5 testEnd with finalLedCnt=%d\n\r ",(int)finalLedCnt);
    printf("\n\r");
    while(1){}
}

/*******************************************************************************
 End of File
*/

