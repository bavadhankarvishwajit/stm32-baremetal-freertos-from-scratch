# FreeRTOS on STM32F030R8 (Bare-Metal)

A complete **Bare-Metal FreeRTOS implementation** for the **STM32F030R8 (NUCLEO-F030R8)** without using **HAL**, **LL Drivers**, or **CubeMX FreeRTOS integration**.

This project demonstrates how to manually integrate the FreeRTOS kernel into a bare-metal STM32 project and understand how the scheduler, context switching, and Cortex-M0 interrupts work internally.

---

## Project Overview

The objective of this project was to learn FreeRTOS from the ground up by integrating it manually into a bare-metal STM32 application instead of relying on auto-generated code.

The project controls the onboard **LD2 LED (PA5)** using two independent FreeRTOS tasks scheduled by the FreeRTOS kernel.

---

## Features

- Bare-Metal STM32 Programming
- Direct Register Programming
- Manual FreeRTOS Integration
- No HAL Library
- No LL Drivers
- No CubeMX FreeRTOS
- Cortex-M0 FreeRTOS Port
- Two Concurrent FreeRTOS Tasks
- Software Scheduling
- Task Context Switching
- FreeRTOS Heap Management (heap_4)
- GPIO Driver Written from Scratch
- Manual FreeRTOS Configuration

---

## Hardware

- STM32 NUCLEO-F030R8
- STM32F030R8T6 (ARM Cortex-M0)
- Onboard LED (PA5)

---

## Software

- STM32CubeIDE
- GCC ARM Embedded Toolchain
- FreeRTOS Kernel

---

## Project Structure

```
Project
│
├── Inc
│   ├── FreeRTOSConfig.h
│   ├── gpio.h
│   ├── tasks.h
│   └── system.h
│
├── Src
│   ├── main.c
│   ├── gpio.c
│   ├── tasks.c
│   ├── hooks.c
│   └── system.c
│
├── Startup
│   └── startup_stm32f030r8tx.s
│
├── FreeRTOS
│   ├── tasks.c
│   ├── queue.c
│   ├── list.c
│   ├── timers.c
│   ├── event_groups.c
│   ├── portable
│   └── MemMang
│
└── STM32F030R8TX_FLASH.ld
```

---

## Execution Flow

```
Power ON
    │
    ▼
Reset_Handler
    │
    ▼
SystemInit()
    │
    ▼
main()
    │
    ▼
GPIO_Init()
    │
    ▼
xTaskCreate(Task1)
    │
    ▼
xTaskCreate(Task2)
    │
    ▼
vTaskStartScheduler()
    │
    ▼
SVC_Handler
    │
    ▼
Task1
    │
    ▼
SysTick
    │
    ▼
PendSV
    │
    ▼
Task2
    │
    ▼
Task1
    │
   ...
```

---

## FreeRTOS Concepts Demonstrated

- Task Creation
- Task Scheduling
- Round-Robin Scheduling
- Preemptive Scheduling
- Context Switching
- SysTick Interrupt
- PendSV Interrupt
- SVC Handler
- Task Delay
- FreeRTOS Heap Allocation
- Task Stack Allocation

---

## Key Learning Outcomes

- Understanding ARM Cortex-M0 startup sequence
- Manual FreeRTOS kernel integration
- Bare-metal GPIO programming
- Cortex-M interrupt handling
- Scheduler initialization
- Context switching
- FreeRTOS task management
- Memory allocation using heap_4
- Embedded firmware debugging using STM32CubeIDE

---

## Future Improvements

- UART Driver
- Queue Communication
- Binary Semaphore
- Counting Semaphore
- Mutex
- Event Groups
- Software Timers
- ADC Driver
- External Interrupts
- SPI Driver
- I2C Driver
- Task Notifications

---

## Repository Purpose

This repository is intended as a learning resource for engineers who want to understand **how FreeRTOS actually works internally** instead of simply using CubeMX-generated projects.

It focuses on understanding:

- ARM Cortex-M0 Architecture
- FreeRTOS Kernel
- Scheduler
- Interrupt Handling
- Context Switching
- Bare-Metal Firmware Development

---

## Author

**Vishwajit Mahesh Bavadhankar**

Embedded Systems Engineer | IoT Engineer | Firmware Developer
