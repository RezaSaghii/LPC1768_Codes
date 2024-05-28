#include "lpc17xx_gpio.h"


const uint8_t segmentTable[4][8]={
    {0x00, 0x7e, 0x0a, 0x1a, 0x2a, 0x4e, 0x00, 0x00}, // R
    {0x00, 0x7e, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x00}, // E
    {0x00, 0x42, 0x62, 0x52, 0x4a, 0x46, 0x42, 0x00}, // Z
    {0x00, 0x7e, 0x12, 0x12, 0x12, 0x12, 0x7e, 0x00}  // A
};

void Delay()
{
   for(uint16_t count=0;count<40000;count++)
   {     
   }
}

int main()
{  
  uint8_t myNum=0, myNum1=0, countOfDelay=0, countOfDelay1=0;
  
  FIO_ByteSetDir(1,2,0xFF,1);
  GPIO_SetDir(2, (1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8), 1);
  
  while(1)
  {    
    for (uint8_t i = 1; i <= 8; i++) {
      GPIO_ClearValue(2, (1 << i));
      GPIO_SetValue(2, (1 << i));
      FIO_ByteSetValue(1, 2, segmentTable[myNum][myNum1 + i - 1]);
      FIO_ByteClearValue(1, 2, ~segmentTable[myNum][myNum1 + i - 1]);
      Delay();
      GPIO_ClearValue(2, (1 << i));
    }

    countOfDelay++;
    countOfDelay1++;
    if (countOfDelay == 24)
    {
      countOfDelay = 0;
      myNum++;
      if (myNum == 4){
        myNum = 0;
      }
    }
    if (countOfDelay1 == 3)
    {
      countOfDelay1 = 0;
      myNum1++;
      if (myNum1 == 8){
        myNum1 = 0;
      }
    }
  }
}
