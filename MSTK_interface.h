/***********************************************************/
/* Author 	: Khaled Elsayed							   */ 
/* Date  	: 21 May 2023								   */
/* Version  :  V01										   */
/***********************************************************/
#ifndef MSTK_INTERFACE_H
#define MSTK_INTERFACE_H



/*  Apply Clock choice from configuration file 
	Disable Systick interrupt
	Disable systick								*/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void (*Copy_ptr)(void));

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_GetElapsedTime(void);

u32 MSTK_GetRemainingTime(void);

#endif
