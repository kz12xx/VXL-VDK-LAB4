/*
 * global.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Le HUy
 */

#include "global.h"
int status_READCMD = CMD_STR;
int status_UART = RST_CMD;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_count = 0;
uint8_t uart_flag = 0;

char str[40];
uint32_t ADC_value = 0;
