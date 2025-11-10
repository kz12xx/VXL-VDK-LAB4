/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Le HUy
 */

#include "global.h"
#include "command_parser_fsm.h"

void command_parser_fsm(){
	switch(status_READCMD) {
		case CMD_STR:
			if(temp == '!') {
				status_READCMD = CMD_END;
				command_count = 0;
			}
			break;

		case CMD_END:
			if(temp == '#') {
				status_READCMD = CMD_STR;
				command[command_count] = '\0';
				uart_flag = 1;
			} else if (temp == '!')	command_count = 0;
			else {
				command[command_count++] = temp;
				if (command_count == MAX_BUFFER_SIZE) command_count = 0;
			}
			break;
		default:
			break;
	}
}
