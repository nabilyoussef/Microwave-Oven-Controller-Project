#include "tm4c123gh6pm.h"
#include "delay.h"
#include "ports.h"

//pe0-3 rows inputs, pc4-7 colomns outputs
#define  RowsSize  4
#define  ColsSize  4

unsigned  char symbol[RowsSize][ColsSize] = {{ '1', '2',  '3', 'A'},      
                                             { '4', '5',  '6', 'B'},      
                                             { '7', '8',  '9', 'C'},      
                                             { '*', '0',  '#', 'D'}};


unsigned char keypad_scan(void)
{
  while(1)
  {
volatile int i,j;
    for(i = 0; i < 4; i++)    //Scan columns loop
    {
      GPIO_PORTC_DATA_R = (1 << (i+4));
      delayUs(2);
      for(j = 0; j < 4; j++)  //Scan rows
      {
        if((GPIO_PORTE_DATA_R & 0x0f) & (1 << (j+1)))
          return symbol[j][i];
      }
    }
  }
}
