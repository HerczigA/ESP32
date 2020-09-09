#include "GPIO_setup.h"
#include <esp_err.h>
#include <driver/include/driver/gpio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <esp-idf\components\esp32\include\esp_sleep.h>
#include <project\alarm_system\param.h>

init_t init_GPIO(RTC_DATA_ATTR uint8_t *gpio, const uint8_t len )
{    
    // bool error = false;
    if(!( gpio && len) )
        return INIT_FAILURE_ARG;

    gpio_config_t *conf =(gpio_config_t*) malloc(len*sizeof(gpio_config_t));
    esp_err_t *result =(esp_err_t*) malloc(len*sizeof(esp_err_t));
    // esp_intr_enable

    if( !(conf && result) )
        return INIT_FAILURE_MALLOC;

    for(uint8_t i = 0; i < len; i++)
    {
        if (GPIO_IS_VALID_GPIO(gpio[i]))
        {
            // error = true;
            // log.info();
            break;
        }
        
            
        conf[i].pin_bit_mask = gpio[i];
        conf[i].intr_type = GPIO_INTR_HIGH_LEVEL;
        conf[i].mode = GPIO_MODE_INPUT;
        // pull up and enable masking strange...
        conf[i].pull_up_en = ( i ? GPIO_PULLUP_ENABLE : GPIO_PULLUP_ENABLE ) | GPIO_PULLUP_ONLY;
        conf[i].pull_down_en =( i ?  GPIO_PULLDOWN_DISABLE : GPIO_PULLDOWN_ENABLE) | GPIO_PULLUP_ONLY;
        result[i] = gpio_config(conf);
        if (i == 0)
        {
            gpio_intr_enable(gpio[i]);
            esp_sleep_enable_ext0_wakeup(gpio[i], HIGH);
        }
        
    }

    for(uint8_t i = 0; i < len; i++)
    {
        if(result[i] == ESP_ERR_INVALID_ARG )
            gpio_reset_pin(gpio[i]);

        free(conf);
        free(result);
        conf++;
        result++;
    }
    

    return INIT_SCCSFULL;
}


