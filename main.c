/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "Dio_interface.h"
#include "MSTK_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "Rania.h"




void main(void)
{
	/* Initialize Clock System */
	RCC_voidInitSysClock();
	/* Enable Peripheral 2 on APP2 bus (GPIOA)*/
	RCC_voidEnableClock(RCC_APB2,2);
	/* Enable Peripheral 12 on APP2 bus (SPI)*/
	RCC_voidEnableClock(RCC_APB2,12);


	/* TFT PINS DIRECTION*/

	Mgpio_voidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	Mgpio_voidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);
	Mgpio_voidSetPinDirection(GPIOA,7,OUTPUT_SPEED_2MHZ_AFPP);
	Mgpio_voidSetPinDirection(GPIOA,5,OUTPUT_SPEED_2MHZ_AFPP);


	MSTK_voidInit();

	SPI1_voidInit();

	HTFT_voidInit();
	HTFT_voidDisplayImage(arr);



	while(1)
	{




	}



}




