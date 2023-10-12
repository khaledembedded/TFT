/***********************************************************/
/* Author 	: Khaled Elsayed							   */ 
/* Date  	: 21 May 2023								   */
/* Version  :  V01										   */
/***********************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MSTK_interface.h"
#include"MSTK_private.h"
#include"MSTK_config.h"

volatile u8 count;

void MSTK_voidInit(void)
{
	#if CLKSOURCE == CLKSOURCE_AHB_DIV

	SET_BIT(STK_CTRL,2);

	#elif CLKSOURCE == CLKSOURCE_AHB_DIV_8
	CLR_BIT(STK_CTRL,2);
	#endif

	/*DISABLE INT*/
	CLR_BIT(STK_CTRL,1);
	/*DISABLE STK*/
	CLR_BIT(STK_CTRL,0);
}


void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK_LOAD=Copy_u32Ticks;
	SET_BIT(STK_CTRL,0);
	
	while(GET_BIT(STK_CTRL,16) == 0);
	STK_LOAD=0;
	STK_VAL=0;
	
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	STK_LOAD=Copy_u32Ticks;
	SET_BIT(STK_CTRL,1);
	SET_BIT(STK_CTRL,0);
	Callback=Copy_ptr;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	count++;
	STK_LOAD=Copy_u32Ticks;
	SET_BIT(STK_CTRL,1);
	SET_BIT(STK_CTRL,0);
	Callback=Copy_ptr;

}

void MSTK_voidStopInterval(void)
{
	/*DISABLE INT*/
	CLR_BIT(STK_CTRL,1);
	/*DISABLE STK*/
	CLR_BIT(STK_CTRL,0);
	count=0;
}

u32 MSTK_GetElapsedTime(void)
{
	return (STK_LOAD-STK_VAL);
}

u32 MSTK_GetRemainingTime(void)
{
	
	return STK_VAL;
}



void SysTick_Handler(void)
{

	Callback();	
	if(count>0)
	{
		if(count>255)
		{
			count=1;

		}

	}
	else
	{
		CLR_BIT(STK_CTRL,0);
	}

}
