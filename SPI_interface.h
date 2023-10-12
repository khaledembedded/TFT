/***********************************************************/
/* Author 	: Khaled Elsayed							   */ 
/* Date  	: 21 May 2023								   */
/* Version  :  V01										   */
/***********************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



void SPI1_voidInit(void);
void SPI_voidSendReceiveSynch(u8 Copy_u8SendData,u8* Copy_u8RecieveData);



#endif