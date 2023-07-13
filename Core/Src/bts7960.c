/*
 * bts7960.c
 *
 *  Created on: Jul 13, 2023
 *      Author: CANAVAR-32
 */

#include "bts7960.h"

void bts7960_init (		bts7960_config* bts7960_config,
						TIM_HandleTypeDef* 		Timer_Handle,
						uint16_t				Timer_Channel,
						GPIO_TypeDef*			En_GPIOx,
						uint16_t				En_GPIO_Pin)
{
	bts7960_config->Timer_Handle	= Timer_Handle;
	bts7960_config->Timer_Channel  	= Timer_Channel;

	bts7960_config->En_GPIOx		= En_GPIOx;
	bts7960_config->En_GPIO_Pin		= En_GPIO_Pin;
}

void bts_start(bts7960_config* bts7960_config, uint16_t state){

	if(state == START){
		bts7960_config->bts_set.durum = state;
		HAL_GPIO_WritePin(bts7960_config->En_GPIOx, bts7960_config->En_GPIO_Pin, GPIO_PIN_SET);
		HAL_TIM_PWM_Start_IT(bts7960_config->Timer_Handle, bts7960_config->Timer_Channel);
		__HAL_TIM_SET_COMPARE(bts7960_config->Timer_Handle, bts7960_config->Timer_Channel, 200);

	}
	else{
		bts7960_config->bts_set.durum = state;
		HAL_GPIO_WritePin(bts7960_config->En_GPIOx, bts7960_config->En_GPIO_Pin, GPIO_PIN_RESET);
		HAL_TIM_PWM_Stop_IT(bts7960_config->Timer_Handle, bts7960_config->Timer_Channel);

	}
}
