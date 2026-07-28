#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"
#include "tasks.h"

int main(void)
{
    GPIO_Init();

    xTaskCreate(Task1,
                "LED1",
                128,
                NULL,
                2,
                NULL);

    xTaskCreate(Task2,
                "LED2",
                128,
                NULL,
                2,
                NULL);

    vTaskStartScheduler();

    while(1)
    {
    }
}
