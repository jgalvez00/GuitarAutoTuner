//============================================================================
// lcd.h: Adapted from the lcdwiki.com examples.
//============================================================================

#ifndef __MENU_H
#define __MENU_H
#include "stdlib.h"
#include "main.h"
#include "lcd.h"
extern int goleft;
extern int goright;
extern const char* menu[3];
extern uint32_t prev;
extern uint32_t curr;
void menu_home();
//This is where the home display functionalities are housed.
void menu_move(int selectIndex);
void menu_select(int selectIndex);
void Manualmode();
void Infomode();
void Info_move(int selectIndex);
int Info_select(int selectIndex);
void stepperMotor(int direction, int per, int angle, int mode);
void Tunemode();
void Tune_move(int scrollidx, int selectIndex, int enable);
int pegDisplay();
void peg_move(int selectIndex);
int peg_select(int selectIndex);
uint8_t updateToggleHistory(uint8_t button);

#endif
