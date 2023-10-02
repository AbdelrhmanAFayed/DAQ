#include "Travel.h"



uint32_t AD_buff = 0;

uint32_t length = 0 ;


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