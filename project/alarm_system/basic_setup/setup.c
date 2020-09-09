#include "setup.h"
#include "GPIO/GPIO_setup.h"
#include <soc\soc\include\soc\interrupts.h>
#include ".\project\alarm_system\param.h"
#include <esp-idf\components\xtensa\include\esp_attr.h>
#include <stdint.h>
#include <esp_wifi/include/esp_wifi.h>
#include <esp-idf\components\esp32\include\esp_sleep.h>

// for deep sleeping stored data 
// RTC_DATA_ATTR  int szar = 0; RTC_DATA_ATTR 

int Init_Setup()
{
    const uint8_t MAX_INPUT = 2;
    int result = ESP_OK;
    RTC_DATA_ATTR uint8_t GPIO[MAX_INPUT] = {esp_isr_names[14], esp_isr_names[22]};

    if(init_GPIO(GPIO, MAX_INPUT) != result)
        return INIT_SETUP_ERROR;

    result = esp_sleep_enable_ext0_wakeup(GPIO[0], HIGH);
    if( result != ESP_OK)
    {
        //log
        return result;
    }
        
}


int deepsleep()
{
    esp_deep_sleep_start();
    
}
