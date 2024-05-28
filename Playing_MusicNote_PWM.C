#include "LPC17xx.h"

void PWM1_Init(uint32_t frequency)
{
    uint32_t pclk, pwmClock;
    uint32_t matchValue;

    LPC_SC->PCONP |= (1 << 6);

    LPC_SC->PCLKSEL0 &= ~(3 << 12);
    LPC_SC->PCLKSEL0 |= (1 << 12);

    LPC_PINCON->PINSEL4 &= ~(3 << 0);
    LPC_PINCON->PINSEL4 |= (1 << 0);

    LPC_PWM1->PCR = (1 << 9);

    LPC_PWM1->TCR = (1 << 1);

    pclk = SystemCoreClock / 4;

    pwmClock = pclk / 4;
    matchValue = pwmClock / frequency;

    LPC_PWM1->MR0 = matchValue;
    LPC_PWM1->MR1 = matchValue / 2;

    LPC_PWM1->LER = (1 << 0) | (1 << 1);

    LPC_PWM1->TCR = (1 << 0) | (1 << 3);
}

void Delay(uint32_t delay)
{
    for(uint32_t i = 0; i < delay; i++)
    {
        for(uint32_t j = 0; j < 1000; j++)
        {
            
        }
    }
}

void PlayNote(uint32_t frequency, uint32_t duration)
{
    PWM1_Init(frequency);
    Delay(duration);
    LPC_PWM1->TCR = 0;
    Delay(100);
}

int main()
{
    SystemInit();

    while(1)
    {
        // Melody: C4, D4, E4, F4, G4, A4, B4, C5
        PlayNote(262, 500); // C4
        PlayNote(294, 500); // D4
        PlayNote(330, 500); // E4
        PlayNote(349, 500); // F4
        PlayNote(392, 500); // G4
        PlayNote(440, 500); // A4
        PlayNote(494, 500); // B4
        PlayNote(523, 500); // C5

        Delay(2000);
    }

    return 0;
}
