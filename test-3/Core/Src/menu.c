
//============================================================================
// lcd.c: Adapted from the lcdwiki.com examples.
//============================================================================

#include "stm32f0xx.h"
#include <stdint.h>
#include "lcd.h"
#include "menu.h"
const char* menu[3] = {"Info", "Tune", "Manual"};
const char* Tune[7] = {"Back", "Peg1", "Peg2", "Peg3", "Peg4", "Peg5", "Peg6"};
const char* Manual[3] = {"Back", "Tight", "Loose"};
const char* Info[2] = {"Back", "Next"};
const char* peg[3] = {"Back", "Test1", "90"};
const char* pegsel[6] = {"Peg 1", "Peg 2", "Peg 3", "Peg 4", "Peg 5", "Peg 6"};
const char* note[6] = {"E", "A", "D", "G", "B", "E"};
int currentSelectIndex = 0;
int currentScrollIndex = 0;
int goleft = 0;
int goright  =0;
uint32_t prev = 0;
uint32_t curr = 0;
uint8_t lastPressed = -1;
uint8_t lastButton = -1;
uint8_t pressHistory[3] = {0,0,0};
extern const Picture *image;
void menu_home()
{
	while (1)
	  {

		LCD_DrawString(80 ,40,  YELLOW, BLUE,"Home Menu", 16, 0);

		if (goleft == 1) { //pressing left button
			if (currentSelectIndex == 0) {
				//if highlighted choice is very first choice, wrap around to last choice
				menu_move(2);

			} else {
				//else just highlight selection left to previous choice
				menu_move((currentSelectIndex - 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0; //reset left indication flag

		} else if (updateToggleHistory(3)) {
			//select button is pressed
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			menu_select(currentSelectIndex);

		} else if (goright == 1) { //pressing right button
			if (currentSelectIndex == 2) {
				//if highlighted choice is very last choice, wrap around to first choice
						menu_move(0);
			} else {
				//else just highlight selection to previous choice
				menu_move((currentSelectIndex + 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0; // reset right indication flag

		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);


	  }
}
void menu_move(int selectIndex) {
	//just unhighlighting previous choice and highlighting current choice
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, menu[currentSelectIndex], 16, 0);

	currentSelectIndex = selectIndex;
}

void menu_select(int selectIndex) {
	//selection cases of where to go
	//highlight selected choice in red
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, menu[selectIndex], 16, 0);
    lastPressed = selectIndex;

    if(selectIndex == 1)
    {//Tune mode is selected so go to tune display
    	Tunemode();
    }
    else if (selectIndex == 2)
    {//Manual mode is selected so go to manual display
    	Manualmode();
    }
    else if (selectIndex == 0)
    {//Info mode is selected so go to info display
    	Infomode();
    }
}
void Infomode()
{//Info mode that displays product usage and info
	LCD_Clear(BLUE);
	for (int i = 0; i < 2; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Info[i], 16, 0);
	}
	LCD_DrawString(25 ,50,  YELLOW, BLUE,"Info will be displayed", 16, 0);
	//currently nothing is displayed for now
	Info_move(0);

	 while (1)
	  {
		if (goleft == 1) {//going left
			if (currentSelectIndex == 0) {
				Info_move(1); // wrap around if very first choice

			} else {// else just highlight left of previous choice
				Info_move((currentSelectIndex - 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0;
		} else if (updateToggleHistory(3)) {
			//selection button pressed
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			if(Info_select(currentSelectIndex) == 1)
			{//if back selection is pressed, then return to home display
				return;
			}

		} else if (goright == 1) {//right button pressed

			if (currentSelectIndex == 1) {
						Info_move(0);//wrap around if very last choices
			} else { //else highlight right of previous choice
				Info_move((currentSelectIndex + 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0;
		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);

	  }
}
void Info_move(int selectIndex)
{//move highlight to current selection and unhighlight previous selection
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, Info[currentSelectIndex], 16, 0);
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, Info[selectIndex], 16, 0);
	currentSelectIndex = selectIndex;
}
int Info_select(int selectIndex) {
	//highlight selected option in RED
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, Info[selectIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentSelectIndex == 0)
    {//for now, the back button is the only functional option. if more information
     //needs to be displayed, the 'next' option will be used.
    	//Reseting the display to show Home, before returning
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
    	return 1;
    }

    return 0;
}
void Manualmode()
{ //display manual mode
	LCD_Clear(BLUE);
	for (int i = 0; i < 3; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Manual[i], 16, 0);
	}
	LCD_DrawString(25 ,50,  YELLOW, BLUE,"Manually Control drill", 16, 0);
	LCD_DrawString(25 ,75,  YELLOW, BLUE,"Re-String Purpose", 16, 0);
	Manual_move(0, 0, 0);

	//same selction mechanics as Home display
	 while (1)
	  {
		if (goleft == 1) {
			if (currentSelectIndex == 0) {
				Manual_move(2);

			} else {
				Manual_move((currentSelectIndex - 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0;
		} else if (updateToggleHistory(3)) {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			if(Manual_select(currentSelectIndex) == 1)
			{
				return;
			}

		} else if (goright == 1) {

			if (currentSelectIndex == 2) {
						Manual_move(0);
			} else {
				Manual_move((currentSelectIndex + 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0;
		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);

	  }
}
void Manual_move(int selectIndex)
{//highlight current selection and unhighlight previous
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, Manual[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, Manual[currentSelectIndex], 16, 0);
	currentSelectIndex = selectIndex;
}
int Manual_select(int selectIndex) {
	//highlight selected option in red
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, Manual[selectIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentSelectIndex == 0)
    {// back option is selected, reset display to home and return
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
    	currentSelectIndex = 0;
    	return 1;
    }
    else if (currentSelectIndex == 1)
    {//'Tighten' option is selected, move stepper motor to tighten rotation as long as trigger is pressed
    	stepperMotor(0, 15000, 1000, 1);
    }
    else if(currentSelectIndex == 2)
    {//'loosen' option is selected, move stepper motor to loosen rotation as long as trigger is pressed
    	stepperMotor(1, 15000, 1000, 1);
    }
    stopmotor();
    return 0;
}

void stepperMotor(int direction, int per, int angle, int mode)
{// stepper motor control
	if(direction == 0) // directional change
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET); //motor Enable
	change_pwm(per);// this is to change pwm signal in case we want to speed or low down motore
	// change_pwm might not even be used
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);//seting motor to full drive

	if(mode == 1) //Manual stepper rotation
	{startmotor();
	while(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
	{//while trigger button is being pressed, currently mapped to selection button for testing
		nano_wait(5000000);

	}
	}
	else //Angular precise stepper movements
		{
		uint32_t timemotor = per* angle  / 10000 / 1.8 * 1.25; //period * number of steps(angle) / 10000 / 1.8degrees per step * 1.25
		startmotor();
		uint32_t motorstarttime = HAL_GetTick();
		uint32_t currmotor = HAL_GetTick();
		while((HAL_GetTick() - motorstarttime < timemotor) &( updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3))))
		{//while trigger is pressed and angle time is not exceeded, continue running the motor
		}
		}

	//stop motor
	stopmotor();
}
void Tunemode() {
	//introduce scroll index which represents the current index in the list of tune
	/*currentSelectIndex is just representing the index respective to which of current three selection
	on the screen is being highlighted */
	int scrollidx = 0;
	LCD_Clear(BLUE);
	for (int i = 0; i < 3; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[i], 16, 0);
	  }
	//display peg diagram
	LCD_DrawString(95 ,25,  YELLOW, BLUE,"-----", 16, 0);
	LCD_DrawString(60 ,40,  YELLOW, BLUE,"3 - |    | - 4", 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"2 - |    | - 5", 16, 0);
	LCD_DrawString(60 ,80,  YELLOW, BLUE,"1 - |    | - 6", 16, 0);
	LCD_DrawString(95 ,100,  YELLOW, BLUE,"-----", 16, 0);
	LCD_DrawString(100 ,115,  YELLOW, BLUE,"||||", 16, 0);
	LCD_DrawString(100 ,130,  YELLOW, BLUE,"||||", 16, 0);
	Tune_move(0, 0, 0);
	while (1)
	  {
		scrollidx = currentScrollIndex;

		if (goleft == 1) {
			if (currentSelectIndex == 0) {
				if(scrollidx == 0) //special display case when currently going left beyond screen and scroll index is 0
				{//looping scroll options
					LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[6], 16, 0);
					for (int i = 1; i < 3; i++) {
							LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[i-1], 16, 0);
						  }
					Tune_move(6, 0, 0);
				}
				else if(scrollidx == 6) //if scrolling left past screen and current choice is peg6, special display case
				{//looping scroll options
					for (int i = 0; i < 2; i++) {
						LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[5+i], 16, 0);
					}
					LCD_DrawString(75*2 + 25,200,  YELLOW, BLUE, Tune[0], 16, 0);
					Tune_move((currentScrollIndex - 1) % 7, 0, 0);
				}
				else
				{
					//normal changing display options
					for (int i = 0; i < 3; i++) {
					LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[(currentScrollIndex - 1) % 7+i], 16, 0);

				}
					Tune_move((currentScrollIndex - 1) % 7, 0, 0);
			}
			goleft = 0;

			} else {
				if(scrollidx == 0) //no new display options just looping array around
				{
					Tune_move(6, (currentSelectIndex - 1) % 3, 1);
				}
				else{ //normal change
					Tune_move((currentScrollIndex - 1) % 7, (currentSelectIndex - 1) % 3, 1);
				}
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);

		} else if (updateToggleHistory(3)) { //normal selection
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			if(Tune_select(currentSelectIndex) == 1) //if back option is selected
			{
				currentSelectIndex = 0;
				return;
			}


		} else if (goright == 1) { // similar to left conditions just applied to right side of screen

			if (currentSelectIndex == 2) {
				if(currentScrollIndex == 6)
				{	int x = 0;
					for (int i = 5; i < 7; i++) {
						LCD_DrawString(75*x + 25,200,  YELLOW, BLUE, Tune[i], 16, 0);
						x++;
					}
					LCD_DrawString(75*2 + 25,200,  YELLOW, BLUE, Tune[0], 16, 0);
					Tune_move(0, 2, 0);
				}
				else
				{
					if(currentScrollIndex == 0)
						LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[6], 16, 0);
					else
						LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[currentScrollIndex - 1], 16, 0);
					for (int i = 1; i < 3; i++) {
						LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[(currentScrollIndex - 1) % 7+i], 16, 0);
					}
					Tune_move((currentScrollIndex + 1) % 7, 2, 0);
				}
			} else {
				if(scrollidx == 6)
				{
					Tune_move(0, (currentSelectIndex + 1) % 3, 1);
				}
				else
					Tune_move( (currentScrollIndex + 1) % 7,(currentSelectIndex + 1) % 3, 1);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0;
		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);


	  }
}
void Tune_move(int scrollidx, int selectIndex, int enable) {
	//highlight current selection
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, Tune[scrollidx], 16, 0);
	if(enable) //enable is for if unhighlighting previous section is necesary
		LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, Tune[currentScrollIndex], 16, 0);

	currentSelectIndex = selectIndex;
	currentScrollIndex = scrollidx;
}

int Tune_select(int selectIndex) {
	//highlight selected option to red
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, Tune[currentScrollIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentScrollIndex == 0) //back option selected
    {
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    	}
    	LCD_DrawString(25,200,  YELLOW, BLACK, menu[0], 16, 0);
    	currentSelectIndex = 0;
    	return 1;
    }
    else
    {
    	pegDisplay(); //display peg screen

    	//reset Tune display before return
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    	    LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[i], 16, 0);
    	 }

    	currentSelectIndex = 0;
    	currentScrollIndex = 0;
    	LCD_DrawString(95 ,25,  YELLOW, BLUE,"-----", 16, 0);
    	LCD_DrawString(60 ,40,  YELLOW, BLUE,"3 - |    | - 4", 16, 0);
    	LCD_DrawString(60 ,60,  YELLOW, BLUE,"2 - |    | - 5", 16, 0);
    	LCD_DrawString(60 ,80,  YELLOW, BLUE,"1 - |    | - 6", 16, 0);
    	LCD_DrawString(95 ,100,  YELLOW, BLUE,"-----", 16, 0);
    	LCD_DrawString(100 ,115,  YELLOW, BLUE,"||||", 16, 0);
    	LCD_DrawString(100 ,130,  YELLOW, BLUE,"||||", 16, 0);
    	Tune_move(0, 0, 0);
    	return 0;
    }
    return 0;
}
int pegDisplay()
{
	LCD_Clear(BLUE);
	for (int i = 0; i < 3; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, peg[i], 16, 0);
	}
	LCD_DrawString(60 ,40,  YELLOW, BLUE,pegsel[currentScrollIndex-1], 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"Play Note", 16, 0);
	LCD_DrawString(140 ,60,  YELLOW, BLUE, note[currentScrollIndex-1], 16, 0);
	peg_move(0);
	//same select mechanics as Home and Manual display
	while(1)
	{

		if (goleft == 1) {
				if (currentSelectIndex == 0) {
					peg_move(2);

				} else {
					peg_move((currentSelectIndex - 1) % 3);
				}
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0;

			} else if (updateToggleHistory(3)) {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
				if(peg_select(currentSelectIndex) == 1)
				{
					return;
				}

			} else if (goright == 1) {

				if (currentSelectIndex == 2) {
							peg_move(0);
				} else {
					peg_move((currentSelectIndex + 1) % 3);
				}
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright =0;

			} else {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
			}
	}
}
void peg_move(int selectIndex)
{//highlight current option and unhighlight previous option
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, peg[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, peg[currentSelectIndex], 16, 0);
	currentSelectIndex = selectIndex;
}
int peg_select(int selectIndex) {
	//highlight selected option as red
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, peg[selectIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentSelectIndex == 0)
    {
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, peg[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, peg[selectIndex], 16, 0);
    	currentSelectIndex = 0;
    	return 1;
    }
    else if (currentSelectIndex == 1) // this is the incremental test for precise motor movements
    {
    	stepperMotor(0, 15000,45 , 0); //checking 45 degrees
    	HAL_Delay(500);

    		for(int j = 0; j < 10; j++)
    		{
    	if(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    		{//10 degrees
    		stepperMotor(0, 15000,10 , 0);
    		HAL_Delay(500);}
    		}
    		for(int j = 0; j < 10; j++)
    		 {
    		if(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    			{//45 degrees
    			stepperMotor(0, 15000,45 , 0);
    			HAL_Delay(500);}

    		 }
    		for(int j = 0; j < 10; j++)
    		  {//90 degrees
    		   if(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    			   {stepperMotor(0, 15000,90 , 0);
    			   HAL_Delay(500);}
    		  }
    		for(int j = 0; j < 10; j++)
    		    		  {//180 degrees
    		    		   if (updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    		    			   {stepperMotor(0, 15000,180 , 0);
    		    			   HAL_Delay(500);}
    		    		  }
    }
    else if(currentSelectIndex == 2) //this is manual 90 degree motor movement
    {
    	stepperMotor(1, 15000, 90, 0);
    }
    stopmotor();
    HAL_Delay(100);
    return 0;
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
