#ifndef __ENCODER_H
#define __ENCODER_H
#include <stm32f1xx_hal.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"




#ifndef ENCODER_TIM
#define ENCODER_TIM                            htim2
#endif



/*max angle before the timer auto reset*/
#define MAX_ANGLE 180

extern TIM_HandleTypeDef htim2;

extern ADC_HandleTypeDef hadc1;

extern DMA_HandleTypeDef hdma_adc1;

/*Number of pulses per one revolution "dependes on the encoder"*/
#define PPR  400 

#define TML 100







void TIM_ResetCounter(TIM_TypeDef* TIMx);
void button_Encoder_reset(void);
void DAQ_Init(void);
int16_t Encoder_angle(void);
uint16_t Encoder_raw();
uint32_t ADC_RAW();
uint32_t ADC_length();


#endif