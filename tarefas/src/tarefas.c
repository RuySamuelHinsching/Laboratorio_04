#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h" // device drivers
#include "cmsis_os2.h" // CMSIS-RTOS

osThreadId_t thread1_id, thread2_id, thread3_id, thread4_id;

typedef struct LED
{
    uint8_t led;
    int tempo;
} led;

struct LED led_1, led_2, led_3, led_4;

void threadLED(void *arg)
{
  struct LED* led = arg;
  
  uint8_t state = 0;
  int tick = 0;
  int tempo_led = led->tempo;
  
  while(1){
    tick = osKernelGetTickCount();   
    state ^= led->led;
    LEDWrite(led->led, state);
    osDelayUntil(tick + tempo_led);
    
    osThreadYield();
  } // while
} // thread


void main(void)
{
  LEDInit(LED4 | LED3 | LED2 | LED1);
  
  led_1.led = LED1;
  led_1.tempo = 200;
  led_2.led = LED2;
  led_2.tempo = 300;
  led_3.led = LED3;
  led_3.tempo = 500;
  led_4.led = LED4;
  led_4.tempo = 700;
  
  osKernelInitialize();

  thread1_id = osThreadNew(threadLED, &led_1, NULL);
  thread2_id = osThreadNew(threadLED, &led_2, NULL);
  thread3_id = osThreadNew(threadLED, &led_3, NULL);
  thread4_id = osThreadNew(threadLED, &led_4, NULL);

  if(osKernelGetState() == osKernelReady)
    osKernelStart();

  while(1);
} // main
