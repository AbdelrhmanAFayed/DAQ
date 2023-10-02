#include "encoder.h"


/*Stores the raw data of the encoder*/


int16_t static position = 0;

int16_t static counter = 0;

uint32_t AD_buff = 0;

uint32_t length = 0 ;

/*Stores the status of the reset button*/
bool static  button_Encoder_status = 1 ;

void DAQ_Init(void)
{
	/*initalizing the encoder interface on TIM2*/
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
	
	HAL_ADCEx_Calibration_Start(&hadc1);
	
}

uint16_t Encoder_raw()
{
	/*getting the raw data of the encoder*/
	counter = __HAL_TIM_GET_COUNTER(&htim2);
	return counter ; 
	
}

int16_t Encoder_angle()
{
	/*type casting the data so that 65534 >> -1*/
	counter =(int16_t) __HAL_TIM_GET_COUNTER(&htim2);
	
	/*calculating the exact angle by knowing how many pulses per revolution*/
	position = (counter)*360/PPR;
	
	/*checking if the angle is a possible value and reseting it if otherwise*/
	if ( (position >= MAX_ANGLE) || (position <= -1*MAX_ANGLE))
		{
			TIM_ResetCounter(TIM2);
			position = 0 ;
		}
	return position ;
}
void button_Encoder_reset (void)
{
	 /*checking the status of the reset button*/
	 button_Encoder_status = HAL_GPIO_ReadPin( GPIOC , GPIO_PIN_14 );
	
	if( button_Encoder_status == 0 )
	{
		TIM_ResetCounter(TIM2);
		position = 0 ;
	}
}
void TIM_ResetCounter(TIM_TypeDef* TIMx)
{
	
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
	
	/*setting the counter register to zero to reset*/
  TIMx->CNT = 0;
	
}
uint32_t ADC_RAW()
{
	HAL_ADC_Start_DMA(&hadc1, &AD_buff, 1);
	
	return AD_buff;
}

uint32_t ADC_length()
{
	HAL_ADC_Start_DMA(&hadc1, &AD_buff, 1);
	
	length = AD_buff / (4096/TML) ;
	
	return length;
}