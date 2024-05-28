#include <LPC17xx.h>
#define DATAPORT 0x00000ff0;
int x;
int d;
void delay_ms(unsigned int x){
    unsigned int j , k;
    for(j = 0 ; j < x ; j++)
       for(k = 0 ; k < x ; k++);
}

int main(void){
LPC_GPIO0 -> FIODIR = 0xffff;
   x = 180; // input the amount of rotation you want
   d = x/60;
   while (1){
    LPC_GPIO0 -> FIOPIN = 1;
    delay_ms(4000);
    if(x % 60 == 0 && d == 0)
       break;
    LPC_GPIO0 -> FIOPIN = 2;
    delay_ms(4000);
    if(x % 60 == 15 && d == 0)
       break;
    LPC_GPIO0 -> FIOPIN = 4;
    delay_ms(4000);
    if(x % 60 == 30 && d == 0)
       break;
    LPC_GPIO0 -> FIOPIN = 8;
    delay_ms(4000);
    if(x % 60 == 45 && d == 0)
       break;
    
    d--;
   }
}
