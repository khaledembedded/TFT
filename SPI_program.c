/***********************************************************/
/* Author 	: Khaled Elsayed							   */ 
/* Date  	: 21 May 2023								   */
/* Version  :  V01										   */
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "Dio_interface.h"
#include "MSTK_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI1_voidInit(void)
{
	/*DISABLE BI DIRECTIONAL MODE*/
	CLR_BIT(SPI1->SPI_CR1,15);
	CLR_BIT(SPI1->SPI_CR1,14);
	
	/*DISABLE CRC CHECK*/
	CLR_BIT(SPI1->SPI_CR1,13);
	CLR_BIT(SPI1->SPI_CR1,12);
	
	
	/*8 BIT DATA TRANSFER*/
	CLR_BIT(SPI1->SPI_CR1,11);
	
	/*FULL DUPLEX MODE*/
	CLR_BIT(SPI1->SPI_CR1,10);
	
	
	/*DISABLE SSM MODE*/
	SET_BIT(SPI1->SPI_CR1,8);
	SET_BIT(SPI1->SPI_CR1,9);
	
	/*MSB FIRST*/
	CLR_BIT(SPI1->SPI_CR1,7);
	
	
	/*CLOCK/2 BAUD*/
	CLR_BIT(SPI1->SPI_CR1,5);
	CLR_BIT(SPI1->SPI_CR1,4);
	CLR_BIT(SPI1->SPI_CR1,3);
	
	/*MASTER MODE*/
	SET_BIT(SPI1->SPI_CR1,2);

	/*1 IDLE COLOCK POLARITY*/
	SET_BIT(SPI1->SPI_CR1,1);
	
	/*WRITE THEN READ COLOCK PHASE*/
	SET_BIT(SPI1->SPI_CR1,0);
	
	/*DISABLE SPI*/
	SET_BIT(SPI1->SPI_CR1,6);
	
	SPI1->SPI_CR1=0x0347;
	
	
}


void SPI_voidSendReceiveSynch(u8 Copy_u8SendData,u8* Copy_u8RecieveData)
{
	
	Mgpio_voidSetPinValue(SPI_SLAVE_SELECT_PIN,0);
	SPI1->SPI_DR=Copy_u8SendData;
	while(GET_BIT(SPI1->SPI_SR,7) == 1);
	*Copy_u8RecieveData=SPI1->SPI_DR;
	Mgpio_voidSetPinValue(SPI_SLAVE_SELECT_PIN,1);
	
}
