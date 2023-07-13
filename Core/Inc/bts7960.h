/*
 * bts7960.h
 *
 *  Created on: Jul 13, 2023
 *      Author: CANAVAR-32
 */

#include "stm32f4xx.h"
#ifndef INC_BTS7960_H_
#define INC_BTS7960_H_

typedef enum{
	STOP,
	START,
}bts_state;


typedef struct{
	TIM_HandleTypeDef* 		Timer_Handle;
	uint16_t				Timer_Channel;

	GPIO_TypeDef*			En_GPIOx;
	uint16_t				En_GPIO_Pin;

	struct{
		uint16_t durum;
	}bts_set;

}bts7960_config;

void bts7960_init (	bts7960_config* bts7960_config,
						TIM_HandleTypeDef* 		Timer_Handle,
						uint16_t				Timer_Channel,
						GPIO_TypeDef*			En_GPIOx,
						uint16_t				En_GPIO_Pin);

void bts_start(bts7960_config* bts7960_config, uint16_t state);

#endif /* INC_BTS7960_H_ */
