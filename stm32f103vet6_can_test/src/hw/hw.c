/*
 * hw.c
 *
 *  Created on: Mar 14, 2021
 *      Author: sungt
 */


#include "hw.h"


void hwInit(void)
{
	bspInit();

	//TODO: HW 초기화 설정 (3)
	uartInit();
	MX_CAN_Init();
	gpioInit();
	ledInit();

}
