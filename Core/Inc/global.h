/*
 * global.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "software_timer.h"
#include "command_parser_fsm.h"
#include "uart_communication_fsm.h"

#define MAX_BUFFER_SIZE 30
extern char str[40];
extern uint32_t ADC_value;

// FOR FSMS
#define CMD_STR 	0
#define CMD_END		1

#define RST_CMD 	10
#define SEND_ADC	11
#define OK_CMD 		12

extern int status_READCMD;
extern int status_UART;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t uart_flag;
extern uint8_t command[MAX_BUFFER_SIZE];
extern uint8_t command_count;

#endif /* INC_GLOBAL_H_ */
