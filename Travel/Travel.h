#ifndef __Travel_H
#define __Travel_H
#include <stm32f1xx_hal.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"




#ifndef Travel_ADC 
#define Travel_ADC                           
#endif




extern ADC_HandleTypeDef hadc1;

extern DMA_HandleTypeDef hdma_adc1;


#define TML 100




uint32_t ADC_RAW();
uint32_t ADC_length();


#endif