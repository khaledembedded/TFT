/***********************************************************/
/* Author 	: Khaled Elsayed							   */ 
/* Date  	: 21 May 2023								   */
/* Version  :  V01										   */
/***********************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



typedef struct
{
	volatile u32  SPI_CR1;
	volatile u32  SPI_CR2;
	volatile u32  SPI_SR;
	volatile u32  SPI_DR;
	volatile u32  SPI_CRCPR;
	volatile u32  SPI_RXCRCR;
	volatile u32  SPI_TXCRCR;
	volatile u32  SPI_I2SCFGR;
	volatile u32  SPI_I2SPR;

}SPI_Register;

#define SPI1   ((SPI_Register*)0x40013000)

#endif
