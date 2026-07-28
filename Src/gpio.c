#include <stdint.h>
#include "gpio.h"

#define RCC_BASE        0x40021000UL
#define GPIOA_BASE      0x48000000UL

#define RCC_AHBENR      (*(volatile uint32_t *)(RCC_BASE + 0x14))

#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_BSRR      (*(volatile uint32_t *)(GPIOA_BASE + 0x18))

void GPIO_Init(void)
{
    /* Enable GPIOA Clock */
    RCC_AHBENR |= (1U << 17);

    /* PA5 Output */
    GPIOA_MODER &= ~(3U << (5 * 2));
    GPIOA_MODER |=  (1U << (5 * 2));
}

void LED_ON(void)
{
    GPIOA_BSRR = (1U << 5);
}

void LED_OFF(void)
{
    GPIOA_BSRR = (1U << (5 + 16));
}

void LED_Toggle(void)
{
    static uint8_t state = 0;

    if(state)
        LED_OFF();
    else
        LED_ON();

    state ^= 1;
}
