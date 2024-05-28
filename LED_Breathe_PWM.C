#include "LPC17xx.h"

void PWM_Init() {

    LPC_SC->PCONP |= (1 << 6);

    LPC_PINCON->PINSEL4 &= ~(3 << 0);
    LPC_PINCON->PINSEL4 |= (1 << 0);


    LPC_PWM1->PR = 0;


    LPC_PWM1->MR0 = 1000;


    LPC_PWM1->MR1 = 0;


    LPC_PWM1->LER = (1 << 0) | (1 << 1);


    LPC_PWM1->TCR = (1 << 0) | (1 << 3);


    LPC_PWM1->PCR = (1 << 9);
}

void PWM_SetDutyCycle(uint32_t duty) {

    LPC_PWM1->MR1 = duty;
    LPC_PWM1->LER = (1 << 1);
}

int main() {
    PWM_Init();

    uint32_t dutyCycle = 0;
    int increment = 10;

    while(1) {
        PWM_SetDutyCycle(dutyCycle);

        for (volatile int i = 0; i < 100000; i++);


        dutyCycle += increment;
        if (dutyCycle >= 1000 || dutyCycle <= 0) {
            increment = -increment;
        }
    }

    return 0;
}
