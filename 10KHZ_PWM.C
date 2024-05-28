#include "LPC17xx.h"

void PWM_Init() {

    LPC_SC->PCONP |= (1 << 6);


    LPC_PINCON->PINSEL4 &= ~(3 << 0);
    LPC_PINCON->PINSEL4 |= (1 << 0);

    LPC_PWM1->PR = 0;


    LPC_PWM1->MR0 = 10000;

    LPC_PWM1->MR1 = 5000;

    LPC_PWM1->LER = (1 << 0) | (1 << 1);

    LPC_PWM1->TCR = (1 << 0) | (1 << 3);

    LPC_PWM1->PCR = (1 << 9);
}

int main() {
    PWM_Init();

    while(1) {
        
    }

    return 0;
}
