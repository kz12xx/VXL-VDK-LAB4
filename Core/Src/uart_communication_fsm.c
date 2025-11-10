/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Le HUy
 */

#include "global.h"
#include "command_parser_fsm.h"
#include "uart_communication_fsm.h"

void uart_communication_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2){
	switch(status_UART) {

	case RST_CMD:
		if (uart_flag == 1) {
			uart_flag = 0;
			if (command[0] == 'R' && command[1] == 'S' && command[2] == 'T') {
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				status_UART = SEND_ADC;
			}
		}
		break;

	case SEND_ADC:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 1000);
		status_UART = OK_CMD;
		setTimer2(3000);
		break;

	case OK_CMD:
		if (uart_flag == 1) {
			uart_flag = 0;
			if (command[0] == 'O' && command[1] == 'K') {
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				status_UART = RST_CMD;
				clearTimer(2);
			}
		}
		if(timer2_flag == 1) {
			status_UART = SEND_ADC;
			setTimer2(3000);
		}
		break;
	default:
		break;
	}
}
