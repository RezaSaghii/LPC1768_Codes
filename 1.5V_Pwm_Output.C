#include "LPC17xx.h"

#define PWM_PIN (1 << 2)

void initPWM(void) {
    
    LPC_SC->PCONP |= (1 << 6);


    LPC_PINCON->PINSEL4 &= ~(3 << 4);
    LPC_PINCON->PINSEL4 |= (1 << 4);


    LPC_PWM1->PCR = (1 << 11);


    uint32_t pwmFreq = 20000;
    uint32_t pclk = SystemCoreClock / 4;
    uint32_t matchValue = pclk / pwmFreq;

    LPC_PWM1->MR0 = matchValue;
    LPC_PWM1->MR3 = (matchValue * 1500) / 3300;


    LPC_PWM1->LER |= (1 << 0) | (1 << 3);


    LPC_PWM1->TCR = (1 << 0) | (1 << 3);
}

int main(void) {
    SystemInit();
    initPWM();

    while (1) {
       
    }
}
