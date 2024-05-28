#include "LPC17xx.h"

void Delay()
{
    for(uint32_t count = 0; count < 1000000; count++) {
        
    }
}

int main()
{  
    
    LPC_GPIO1->FIODIR |= ((1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20));

    LPC_GPIO1->FIODIR &= ~((1 << 21) | (1 << 22) | (1 << 23) | (1 << 24) | (1 << 25));

    while (1) {

        if (!(LPC_GPIO1->FIOPIN & (1 << 21))) {
            LPC_GPIO1->FIOSET = (1 << 16);
        } else {
            LPC_GPIO1->FIOCLR = (1 << 16);
        }
        

        if (!(LPC_GPIO1->FIOPIN & (1 << 22))) {
            LPC_GPIO1->FIOSET = (1 << 17);
        } else {
            LPC_GPIO1->FIOCLR = (1 << 17);
        }


        if (!(LPC_GPIO1->FIOPIN & (1 << 23))) {
            LPC_GPIO1->FIOSET = (1 << 18);
        } else {
            LPC_GPIO1->FIOCLR = (1 << 18);
        }


        if (!(LPC_GPIO1->FIOPIN & (1 << 24))) {
            LPC_GPIO1->FIOSET = (1 << 19);
        } else {
            LPC_GPIO1->FIOCLR = (1 << 19);
        }


        if (!(LPC_GPIO1->FIOPIN & (1 << 25))) {
            LPC_GPIO1->FIOSET = (1 << 20);
        } else {
            LPC_GPIO1->FIOCLR = (1 << 20);
        }
    }
}
