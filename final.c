#include <stdio.h>
#include <stdlib.h> //for rand()
#include <unistd.h> //for 'usleep function'
#include "gfx5.h"
#include "gfx5.c"
#include "gfxe.h"
#include <math.h>

//function prototypes

//gcc example.c gfx_mac.o -lX11 -lm -I/opt/X11/include/ -L/opt/X11/lib/ -o example


/*--------------------------------------------------------------------------------*/
int main () {
	int loop = 1, action, xsize=800, ysize=600;

	gfx_open(xsize, ysize, "Tamagotchi Borah & Emily");

	while (loop) {
		//set default background image to living room 

		action = ClickMenuBar();
		switch(action) {
			case 1: //feeding pet
				break;

			case 2: //cleaning pet
				break;

			case 3: //putting pet to sleep
				break;

			case 4: //watering pet
				break;

			case 5: //playing with pet
				break;
		}

	}

	
	return 0;
}
/*--------------------------------------------------------------------------------*/

//draws menu bar
void MenuBar(void) {
	gfx_color(255, 204, 229) //color of menu bar
	gfx_fill_rectangle() //draw menu bar
	gfx_color() //color of buttons on menu bar
	gfx_fill_rectangle() //draw food button
	gfx_fill_rectangle() //draw clean button
	gfx_fill_rectangle() //draw sleep button
	gfx_fill_rectangle() //draw water button
	gfx_fill_rectangle() //draw play button
}

//registers user clicks on menu bar
int ClickMenuBar(void) {

	if (gfx_event_waiting()) {

	}

}

//feeding pet
void feed(void) {

}


//cleaning pet
void clean(void) {

}


//putting pet to sleep
void sleep(void) {

}


//watering pet
void water(void) {

}


//playing with pet
void play(void) {

}







