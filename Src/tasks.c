#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"

void Task1(void *pvParameters)
{
    (void)pvParameters;

    while(1)
    {
        LED_ON();

        for(volatile uint32_t i=0;i<200000;i++);
    }
}

void Task2(void *pvParameters)
{
    (void)pvParameters;

    while(1)
    {
        LED_OFF();

        for(volatile uint32_t i=0;i<200000;i++);
    }
}
