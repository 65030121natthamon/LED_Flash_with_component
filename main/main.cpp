#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

extern "C" void app_main(void)
{
    int i = 0;
    int direction = 1; 

    while(1)
    {        
        
        for (int j = 0; j < 8; j++) {
            leds[j].OFF();
        }

        leds[i].ON();
        
        vTaskDelay(500/portTICK_PERIOD_MS);
        
        i += direction;

        if (i == 7 || i == 0) {
            direction = -direction;
        }
    }
}
 //65030121
