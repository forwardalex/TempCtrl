
#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#include "stm32g4xx_hal.h"

#endif /* __MAIN_H */
extern float envTemp  ;
#define SWITCH_NUMS 4

typedef struct{
    GPIO_TypeDef *port;
    uint16_t pin;
} SWITCH;

void UpdateSwitch(float* temps ,int size);
float GetTemperature(float vol);