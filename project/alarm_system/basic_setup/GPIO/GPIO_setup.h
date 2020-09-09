#ifndef _GPIO_SETUP_H_
#define _GPIO_SETUP_H_

#include <stdint.h>


typedef uint8_t init_t;

enum init_type
{
    INIT_SCCSFULL,
    INIT_FAILURE_ARG,
    INIT_FAILURE_MALLOC,
    INIT_TYPE
};




init_t init_GPIO(uint8_t*, uint8_t);

#endif