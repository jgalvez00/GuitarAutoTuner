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
//extern const char* menu[3];
extern uint32_t prev;
extern uint32_t curr;
extern int currentSelectIndex;
extern int currentScrollIndex;
typedef void (*title)(); //function pointer
struct display{
	title ttl;//pointer to function that will display or perform action corresponding to selection
	char identity; //identity of display
	const char** selection; //display's selections
	int scrollmax; //max number of choices displayed on the screen at a time
	int selectionmax; //max number of selection that the display contains
	struct display * nextsel; //link to the next display selection
	struct display * childsel;//link to the display's first selection
	struct display * backout; //link to destination when backed out
};

struct selection{
	title point;
	int sid;
	//struct selection *nextsel;
};
//This is where the home display functionalities are housed.
void menu_home();
void initialize();
void move_right();
void move_left();
void manualRotate();
void autoRotate();
void resetSel();
void display_move(int scrollIndex, int selectIndex, int enable);
void display_select(int selectIndex);
void Manualmode();
void Infomode();
void stepperMotor(int direction, int per, int angle, int mode);
void Tunemode();
void pegDisplay();
void battery();
uint8_t updateToggleHistory(uint8_t button);

#endif