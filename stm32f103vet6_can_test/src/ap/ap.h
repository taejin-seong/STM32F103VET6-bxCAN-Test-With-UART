/*
 * ap.h
 *
 *  Created on: Mar 14, 2021
 *      Author: sungt
 */
/* 실질적으로  Main 함수를 담당하는 부분입니다.*/

#ifndef SRC_AP_AP_H_
#define SRC_AP_AP_H_


#include "hw.h"



void apInit(void);

void apBoardLedTest(void);
void apUartTest(void);
void apMCU1CanTest(void); //0x7F3
void apMCU2CanTest(void); //0x7F6








#endif /* SRC_AP_AP_H_ */
