#ifndef BIT_MATH
#define BIT_MATH

/******************************************************/
/*Author     : Khaled Elsayed                         */
/*Date       : 18 MAY 2023                            */
/*Version    : V01                                    */
 /*****************************************************/
 
#define SET_BIT(VAR,BIT)        VAR|=(1<<BIT)
#define CLR_BIT(VAR,BIT)        VAR&=~(1<<BIT)
#define GET_BIT(VAR,BIT)        ((VAR>>BIT)&0x01)
#define TOG_BIT(VAR,BIT)        VAR^=(1<<BIT)




#endif