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
volatile bool tc1ch0TmrExFlag;

char charArray[3] = {'x','y','z'};
volatile uint32_t char2prntIdx; //- index for 'charArray'
void testEnd(void);


void tc1ch0_handler(uintptr_t context)
{
	tc1ch0TmrExFlag=true;
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    printf("\n\r");
    //-SL: printf("\n\r START H3 on SAM9x60_curiosity with at91=intSRAM (SLx: at91-loop_ide) ...");
    printf("\n\r START H3 on SAM9x60_curiosity for production (SLx: at91-sam9x60cur-sdc0) ...");

     //-SL: inits
    myCnt=0;
    finalLedCnt=0;
    tc1ch0TmrExFlag=false;
     //-SL: userbutton defined as GPIOIn but still need to call this fct to enable on MPUs
    SW2_InputEnable();
    char2prntIdx=0; //- default char-to-print = 'b'

    TC1_CH0_TimerStart();
    TC1_CH0_TimerCallbackRegister((TC_TIMER_CALLBACK)tc1ch0_handler, (uintptr_t) NULL);
    
    while ( true )
    {
        if(tc1ch0TmrExFlag)
        {
            tc1ch0TmrExFlag=false;
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
        if(PRESSED == SW2_Get())
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

