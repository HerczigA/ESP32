#include <soc\soc\esp32\include\soc\gpio_caps.h>

#ifdef GPIO_SUPPORTS_RTC_INDEPENDENT
    #undef GPIO_SUPPORTS_RTC_INDEPENDENT
    #define GPIO_SUPPORTS_RTC_INDEPENDENT (1)
#else
    #define GPIO_SUPPORTS_RTC_INDEPENDENT (1)
#endif


#ifndef HIGH
    #define HIGH 1
#endif


#define TIME_TO_PUSH 3
#define uS_TO_S_FACTOR 1000000
