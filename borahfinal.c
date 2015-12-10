#include <stdio.h>
#include <stdlib.h>
#include "gfx5.c"
#include "gfxe.h"

void drawmenu();
void drawstatus();

int main( int argc, char * argv[] ) {

   gfx_open( 1050, 600, "image??" );

   while(1) {
	
	// Read the image data into memory
	unsigned char * bufferPtr = readRAWImage( "livingroom1(bmpsize).bmp", 54 );
	
	// Draw the image on screen
	printRAWImage ( 0, 0, 800, 600, bufferPtr );

	drawmenu();
	drawstatus();

	// Always remember to release your memory!
	free( bufferPtr );
	
	gfx_wait();
   }
}

void drawmenu() {

	int w=gfx_textpixelwidth("MENU", "lucidasans-bold-18");
	float xpos, ypos;

	xpos=830+((190-w)/2);
	ypos=370;

   	gfx_color(255, 255, 255);

	//label
	gfx_changefont("lucidasans-bold-18");
	gfx_text(xpos, ypos, "MENU");
   	
	//box
	gfx_rectangle(830, 350, 190, 220);

	//buttons
	gfx_rectangle(837, 381, 84, 57);
	gfx_rectangle(837, 444, 84, 57);
	gfx_rectangle(837, 507, 84, 57);
	gfx_rectangle(929, 381, 84, 57);
	gfx_rectangle(929, 444, 84, 57);
	gfx_rectangle(929, 507, 84, 57);

}

void drawstatus() {

	int w=gfx_textpixelwidth("STATUS", "lucidasans-bold-18");
	int i;
	float xpos, ypos;
	char barnames[][6]={"FOOD", "WATER", "MOOD", "CLEAN", "SLEEP"};

	xpos=830+((190-w)/2);
	ypos=50;

	//label
	gfx_changefont("lucidasans-bold-18");
	gfx_text(xpos, ypos, "STATUS");


  	gfx_color(255, 255, 255);

	//draw box
	gfx_rectangle(830, 30, 190, 290);

	//draw bars
	for (i=0; i<5; i++) {
		gfx_rectangle(850, 80+(50*i), 150, 20); 
	}
	
	//make bar labels
	
   	gfx_changefont("lucidasans-bold-12");

	for (i=0; i<5; i++) {
		gfx_text(850, 15+62+(50*i), barnames[i]);
	}

}




