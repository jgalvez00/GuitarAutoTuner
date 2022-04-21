
//============================================================================
// lcd.c: Adapted from the lcdwiki.com examples.
//============================================================================

#include "stm32f0xx.h"
#include <stdint.h>
#include "lcd.h"
#include "menu.h"
#include "main.h"
const char* menu[3] = {"Info", "Tune", "Restring"};
const char* Tune[7] = {"Back", "Peg1", "Peg2", "Peg3", "Peg4", "Peg5", "Peg6"};
const char* Manual[3] = {"Back", "Loose", "Tight"};
const char* Info[2] = {"Back", "Battery"};
const char* Peg[3] = {"Back", "Test1", "AutoTune"};
const char* pegsel[6] = {"Peg 1", "Peg 2", "Peg 3", "Peg 4", "Peg 5", "Peg 6"};
const char* note[6] = {"Low E", "A", "D", "G", "B", "High E"};
int currentSelectIndex = 0;
int currentScrollIndex = 0;
int currentPeg = 0;
int goleft = 0;
int goright  =0;
uint32_t prev = 0;
uint32_t curr = 0;
uint8_t lastPressed = -1;
uint8_t lastButton = -1;
uint8_t pressHistory[3] = {0,0,0};
extern const Picture *image;
struct display *currDisplay;

void initialize()
{
	struct display *home = malloc(sizeof(struct display));
	struct display *info = malloc(sizeof(struct display));
	struct display *samp = malloc(sizeof(struct display));
	struct display *tune = malloc(sizeof(struct display));
	struct display *manual = malloc(sizeof(struct display));
	struct display *peg = malloc(sizeof(struct display));
	struct display *rotate = malloc(sizeof(struct display));
	struct display *Auto = malloc(sizeof(struct display));
	struct display *bat = malloc(sizeof(struct display));

	home->ttl = menu_home;
	home->scrollmax = 3;
	home->selectionmax = 3;
	home->backout = NULL;
	home->nextsel = NULL;
	home->childsel = info;
	home->identity = 'h';
	home->selection = menu;
	//info
	info->scrollmax = 2;
	info->selectionmax = 2;
	info->ttl = Infomode;
	info->backout = home;
	info->nextsel = tune;
	info->childsel = bat;
	info->identity = 'i';
	info->selection = Info;

	//info
	bat->scrollmax = 0;
	bat->selectionmax = 0;
	bat->ttl = battery;
	bat->backout = NULL;
	bat->nextsel = NULL;
	bat->childsel = NULL;
	bat->identity = 'b';
	bat->selection = Info;
	//Tune
	tune->scrollmax = 3;
	tune->selectionmax = 7;
	tune->ttl = Tunemode;
	tune->backout = home;
	tune->childsel = peg;
	tune->nextsel = manual;
	tune->identity = 't';
	tune->selection = Tune;

	//Peg
	peg->scrollmax = 3;
	peg->selectionmax = 3;
	peg->ttl = pegDisplay;
	peg->backout = tune;
	peg->childsel = Auto;
	peg->nextsel = NULL;
	peg->identity = 'p';
	peg->selection = Peg;

	//Auto
	Auto->scrollmax = 0;
	Auto->selectionmax = 0;
	Auto->ttl = autoRotate;
	Auto->backout = peg;
	Auto->childsel = NULL;
	Auto->nextsel = samp;
	Auto->identity = 'a';

	//sample
	samp->scrollmax = 0;
	samp->selectionmax = 0;
	samp->ttl = auto_tune;
	samp->backout = peg;
	samp->childsel = NULL;
	samp->nextsel = NULL;
	samp->identity = 'a';

	//Manual
	manual->scrollmax = 3;
	manual->selectionmax = 3;
	manual->ttl = Manualmode;
	manual->backout = home;
	manual->childsel = rotate;
	manual->nextsel = info;
	manual->identity = 'm';
	manual->selection = Manual;

	//backout
	rotate->ttl = manualRotate;
	rotate->scrollmax = 0;
	rotate->selectionmax = 0;
	rotate->backout = NULL;
	rotate->nextsel = NULL;
	rotate->childsel = NULL;
	rotate->identity = 'r';
	//back->selection = null;

	currDisplay = home;
}
struct display *currDisplay;
void menu_home()
{
LCD_DrawString(25,200,  YELLOW, BLACK, menu[0], 16, 0);
LCD_DrawString(80 ,40,  YELLOW, BLUE,"Home Menu", 16, 0);
}
void move_right()
{
	if (currentScrollIndex == (currDisplay->scrollmax -1)) {
					//if highlighted choice is very last choice, wrap around to first choice
					display_move(currentScrollIndex +1, currentSelectIndex+1,2);
				} else {
					//else just highlight selection to previous choice
					display_move(currentScrollIndex +1, currentSelectIndex+1,0);
				}
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
				goright = 0; // reset right indication flag
}
void move_left()
{
	if (currentScrollIndex == 0) {
					//if highlighted choice is very first choice, wrap around to last choice
					display_move(currentScrollIndex -1, currentSelectIndex-1,1);

				} else {
					//else just highlight selection left to previous choice
					display_move(currentScrollIndex -1, currentSelectIndex-1,0);
				}
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
				goleft = 0; //reset left indication flag
}
void display_move(int scrollIndex, int selectIndex, int enable) {
	//just unhighlighting previous choice and highlighting current choice
	if((currDisplay->selectionmax > 3) && (enable > 0))
	{
		if(enable == 1)
		{
			if(selectIndex < 0)
				selectIndex = currDisplay->selectionmax-1;
			LCD_DrawString(25,200,  YELLOW, BLACK, currDisplay->selection[selectIndex], 16, 0);
			int idx = selectIndex;
			for(int i = 1; i < 3; i++)
				{idx++;
				if(idx >= currDisplay->selectionmax)
					idx = 0;
				LCD_DrawString(65*i + 25,200,  YELLOW, BLUE, currDisplay->selection[idx], 16, 0);
				}
			scrollIndex = 0;
		}
		else
		{
			if(selectIndex >= currDisplay->selectionmax)
				selectIndex = 0;
			LCD_DrawString(65*2 +25,200,  YELLOW, BLACK, currDisplay->selection[selectIndex], 16, 0);
			int idx = selectIndex;
			for(int i = 1; i >= 0; i--)
			{idx--;
			if(idx < 0)
				idx = currDisplay->selectionmax-1;
			LCD_DrawString(65*i + 25,200,  YELLOW, BLUE, currDisplay->selection[idx], 16, 0);
			}
			scrollIndex = 2;
		}
		currentPeg = currentSelectIndex-1;
	}
	else
	{
	if(enable == 1)
		{selectIndex = currDisplay->selectionmax-1; scrollIndex = currDisplay->scrollmax-1;}
	else if(enable == 2)
		{selectIndex = 0; scrollIndex = 0;}
	if(selectIndex > currDisplay->selectionmax-1)
		selectIndex = 0;
	else if(selectIndex < 0)
		selectIndex = currDisplay->selectionmax-1;

	LCD_DrawString(65*scrollIndex + 25,200,  YELLOW, BLACK, currDisplay->selection[selectIndex], 16, 0);
	LCD_DrawString(65*currentScrollIndex + 25,200,  YELLOW, BLUE, currDisplay->selection[currentSelectIndex], 16, 0);
	}
	currentSelectIndex = selectIndex;
	currentScrollIndex = scrollIndex;
}

void display_select(int selectIndex) {
	//selection cases of where to go
	//highlight selected choice in red
    LCD_DrawString(65*currentScrollIndex + 25,200,  YELLOW, RED, currDisplay->selection[currentSelectIndex], 16, 0);
    lastPressed = selectIndex;

    if((currentSelectIndex == 0) && (currDisplay->identity != 'h'))
    {//Tune mode is selected so go to tune display
    	currDisplay = currDisplay->backout;
    	LCD_Clear(BLUE);
    	resetSel();
    	currDisplay->ttl();
    }
    else if(currDisplay->childsel != NULL)
    {
    	struct display * child = currDisplay->childsel;
    	int i;
    	if(currDisplay->identity == 'h'){i = 0;}
    	else
    		i = 1;
    	while((i < currentSelectIndex)&&(child->nextsel != NULL))
    	{
    		child = child->nextsel;
    		i++;
    	}

    	if(child->selectionmax > 0)
    	{
    		currDisplay = child;
    		LCD_Clear(BLUE);
    		currDisplay->ttl();
    		resetSel();
    	}
    	else
    	{
    		child->ttl();
    		LCD_DrawString(65*selectIndex + 25,200,  YELLOW, BLACK, currDisplay->selection[selectIndex], 16, 0);
    	}
    }
}
void resetSel()
{
	//LCD_Clear(BLUE);
	LCD_DrawString(25,200,  YELLOW, BLACK, (currDisplay->selection)[0], 16, 0);
	for (int i = 1; i < currDisplay->scrollmax; i++) {
			LCD_DrawString(65*i + 25,200,  YELLOW, BLUE, (currDisplay->selection)[i], 16, 0);
		}
	currentScrollIndex = 0;
	currentSelectIndex = 0;
}
void Infomode()
{//Info mode that displays product usage and info
	LCD_DrawString(25 ,50,  YELLOW, BLUE,"Info will be displayed", 16, 0);
	//currently nothing is displayed for now
}
void Manualmode()
{ //display manual mode
	LCD_DrawString(25 ,50,  YELLOW, BLUE,"Manually Control drill", 16, 0);
	LCD_DrawString(25 ,75,  YELLOW, BLUE,"Re-String Purpose", 16, 0);

}

void manualRotate()
{
	stepperMotor(currentSelectIndex, 7500, 90, 1);
}
void autoRotate()
{
	stepperMotor(currentSelectIndex, 7500, 90, 2);
}
void stepperMotor(int direction, int per, int angle, int mode)
{// stepper motor control
	if(direction == 1) // directional change
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET); //motor Enable
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET); //Boost Enable
	//change_pwm(per);// this is to change pwm signal in case we want to speed or low down motore
	// change_pwm might not even be used
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);//seting motor to full drive

	if(mode == 1) //Manual stepper rotation
	{startmotor();
	while(updateToggleHistory(5) | updateToggleHistory(7) | HAL_GPIO_ReadPin(GPIOB, 1 << (5)) | HAL_GPIO_ReadPin(GPIOB, 1 << (7)))
	{//while trigger button is being pressed, currently mapped to selection button for testing
		nano_wait(5000000);

	}
	}
	else //Angular precise stepper movements
		{
		uint32_t timemotor = per* angle /10000/1.8*3.95; //period * number of steps(angle) / 10000 / 1.8degrees per step * 1.25
		startmotor();
		uint32_t motorstarttime = HAL_GetTick();
		for(int i =0; i < timemotor; i++)
		{
			nano_wait(6000000);
		}
		//while((HAL_GetTick() - motorstarttime < timemotor)/* &( updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))*/)
		//{//while trigger is pressed and angle time is not exceeded, continue running the motor
		//}
		}

	//stop motor
	stopmotor();
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET); //Boost Disable
}
void Tunemode() {
	//introduce scroll index which represents the current index in the list of tune
	/*currentSelectIndex is just representing the index respective to which of current three selection
	on the screen is being highlighted */
	//display peg diagram
	LCD_DrawString(95 ,25,  YELLOW, BLUE,"-----", 16, 0);
	LCD_DrawString(60 ,40,  YELLOW, BLUE,"3 - |    | - 4", 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"2 - |    | - 5", 16, 0);
	LCD_DrawString(60 ,80,  YELLOW, BLUE,"1 - |    | - 6", 16, 0);
	LCD_DrawString(95 ,100,  YELLOW, BLUE,"-----", 16, 0);
	LCD_DrawString(100 ,115,  YELLOW, BLUE,"||||", 16, 0);
	LCD_DrawString(100 ,130,  YELLOW, BLUE,"||||", 16, 0);
}

void pegDisplay()
{
	LCD_DrawString(60 ,40,  YELLOW, BLUE,pegsel[currentSelectIndex-1], 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"Play open", 16, 0);
	LCD_DrawString(140 ,60,  YELLOW, BLUE, note[currentSelectIndex-1], 16, 0);
	currentPeg = currentSelectIndex-1;
}


uint8_t updateToggleHistory(uint8_t button) {
	uint8_t prev = pressHistory[button - 2];
	uint8_t new = HAL_GPIO_ReadPin(GPIOB, 1 << (button));
	pressHistory[button - 2] = new;
	if (lastButton == button && (prev == 1 || new == 1)) return 0;
	else if (prev == 1 && new == 1) {
		lastButton = button;
	} else if (prev == 0 && new == 0){
		lastButton = -1;
	}

	return prev && new;


  /* USER CODE END 3 */
}
