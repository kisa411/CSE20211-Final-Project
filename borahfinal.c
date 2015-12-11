#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for 'usleep function'
#include "gfx5.h"
#include "gfxe.h"

void drawmenu();
void drawstatus();
int foodbarinc(int status, int arr[]); 
int waterbarinc(int status, int arr[]);
int moodbarinc(int status, int arr[]);
int cleanbarinc(int status, int arr[]);
int sleepbarinc(int status, int arr[]);
int foodbardec(int status); 
int waterbardec(int status);
int moodbardec(int status);
int cleanbardec(int status);
int sleepbardec(int status);
void initialbars();
int click(int xpos, int ypos);

int main( int argc, char * argv[] ) {


	int xpos, ypos, loop=1, action;
	int currentbarstatus[5]={144, 144, 144, 144, 144}; //food, water, mood, clean, sleep
	int c;
	int new;
	gfx_open(1050, 600, "TOMODACHI - Borah & Emily");


 	while(loop) {
	
	   // Read the image data into memory
	   unsigned char * bufferPtr = readRAWImage( "livingroom1(bmpsize).bmp", 54 );
	   
	   // Draw the image on screen
	   printRAWImage ( 0, 0, 800, 600, bufferPtr );

	   drawmenu();
	   drawstatus();
	   initialbars();

	   if (gfx_event_waiting()) {

		   c=gfx_wait();
		   if (c==1) {    //return for left click
			   xpos=gfx_xpos();
			   ypos=gfx_ypos();
			   action=click(xpos, ypos);

			   switch (action) {
				case 1:
					//food
					//display food and pet eating
					//increment food bar by 5px each time it is clicked
					new=foodbarinc(currentbarstatus[0], currentbarstatus);
					currentbarstatus[0] = new;
					break;
				case 2:
					//water
					//display water and pet drinking
					//increment water bar by 5px each time it is clicked
					new=waterbarinc(currentbarstatus[1], currentbarstatus);
					currentbarstatus[1] = new;
					break;
				case 3:
					//toy
					//display toy bouncing around
					//clean, sleep, food, water bar decreases
					//increment play bar by 5px each time it is clicked
					new=moodbarinc(currentbarstatus[2], currentbarstatus);
					currentbarstatus[2] = new;
					break;
				case 4:
					//clean
					//move to bathroom automatically
					//when cleaned, fill clean bar
					new=cleanbarinc(currentbarstatus[3], currentbarstatus);
					currentbarstatus[3] = new;
					break;
				case 5:
					//sleep
					//pet moves to bed and sleeps until user wakes it
					//food, water, and fun decreases
					//sleep bar incremented by 5px depending on how long it sleeps
					new=sleepbarinc(currentbarstatus[4], currentbarstatus);
					currentbarstatus[4] = new;
					break;
				case 6:
					//quit
					//display bye bye screen then quit game
					loop=0;
			   }
		   }
	   }


	// Always remember to release your memory!
	free( bufferPtr );
   }
}


int click(int xpos, int ypos) {

	if (xpos>=837 && xpos<=837+84) {
		if (ypos<=381 && ypos >=381+57) {  //button 1: food
	   		return 1;
		}
		else if (ypos<=444 && ypos >=444+57) {  //button 3: toy
			return 3;
		}
		else if (ypos<=507 && ypos >=507+57) {  //button 5: clean
		   	return 5;
		}
	}
	else if (xpos>=929 && xpos<=929+84) { 
	   	if (ypos<=381 && ypos >=381+57) {   //button 2: water
			return 2;
		}
		else if (ypos<=444 && ypos >=444+57) {  //button 4: sleep
			return 4;
		}
		else if (ypos<=507 && ypos >=507+57) {  //button 6: quit
		   	return 6;
		}
	}

	return 0;

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
	gfx_rectangle(837, 381, 84, 57); //food button
	gfx_text(837+30, 381+14, "FOOD"); //button label
	gfx_rectangle(837, 444, 84, 57); //water button
	gfx_text(837+30, 444+14, "WATER"); //button label
	gfx_rectangle(837, 507, 84, 57); //play button
	gfx_text(837+30, 507+14, "PLAY"); //button label
	gfx_rectangle(929, 381, 84, 57); //clean button
	gfx_text(929+30, 381+14, "CLEAN"); //button label
	gfx_rectangle(929, 444, 84, 57); //sleep button
	gfx_text(929+30, 444+14, "SLEEP"); //button label
	gfx_rectangle(929, 507, 84, 57); //quit button
	gfx_text(929+30, 507+14, "QUIT"); //button label

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

void initialbars() {

   int i;

   gfx_color(51, 255, 255);
   for (i=0; i<5; i++) {
   	gfx_fill_rectangle(853, 83+(50*i), 144, 14); //bar is 144 px long
   }

}


int foodbarinc(int status, int currentbarstatus[]) {

   	int inc; //amount to increment
	int newstatus;

	//display pet eating
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//increment food bar after eating
	   	inc=144/10;
			if (status+inc>=144) { //if bar value goes over 144, just set to 144
				gfx_rectangle(853, 83, 144, 14);
	   		}
		   	else if (status+inc<144 && status+inc>0.33*144) {
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, inc+status, 14);
			}
			else if (status+inc<0.33*144 && status+inc>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, inc+status, 14);
			}
	}

	newstatus=status+inc;

	return newstatus;

}

int waterbarinc(int status, int currentbarstatus[]) {

   	int inc; //amount to increment
	int newstatus;

	//display pet drinking
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//increment water bar after eating
	   	inc=144/10;
			if (status+inc>=144) { //if bar value goes over 144, just set to 144
				gfx_rectangle(853, 83, 144, 14);
	   		}
		   	else if (status+inc<144 && status+inc>0.33*144) {
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, inc+status, 14);
			}
			else if (status+inc<0.33*144 && status+inc>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, inc+status, 14);
			}
	}

	newstatus=status+inc;

	return newstatus;

}

int moodbarinc(int status, int currentbarstatus[]) {

   	int inc; //amount to increment
	int newstatus;

	//display pet playing
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//increment mood bar after playing
	   	inc=144/10;
			if (status+inc>=144) { //if bar value goes over 144, just set to 144
				gfx_rectangle(853, 83, 144, 14);
	   		}
		   	else if (status+inc<144 && status+inc>0.33*144) {
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, inc+status, 14);
			}
			else if (status+inc<0.33*144 && status+inc>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, inc+status, 14);
			}
	}


	//ball toy bouncing around screen
	double x, y, dx, dy;
	char c = '0';

	//do random direction 
	do {
		gfx_color(143, 160, 215);

		gfx_fill_circle(x, y, 20); //draw circle while changing its coordinates by specified random amount
		x += dx;
		y += dy;

		gfx_flush(); //after you draw everything you want, ensures that it makes it show onto the screen

		usleep(5000); //makes image stay on screen for specified milliseconds

		gfx_clear(); //clear screen of previous animations

		if (x > 780) { //x-boundaries of graphics window
			x = 780;
			dx = -dx; //re-set location of circle
		} else if (x < 20) {
			x = 20;
			dx = -dx;
		} else if (y > 580) {
			y = 580;
			dy = -dy;
		} else if (y < 20) { //y-boundaries of graphics window
			y = 20;
			dy = -dy;
		}	

		if (c == 1) {
			x = gfx_xpos(); //get mouse location
			y = gfx_ypos(); //get mouse location

			dx = rand()%3; //randomly changes speed of circle
			dy = rand()%3; //randomly changes speed of circle

			c = '0';	
		}	

		if (gfx_event_waiting()) {
			c = gfx_wait(); //repeat loop until user clicks mouse
		}	
	} while (c != 'q'); //do-while 

	foodbardec(currentbarstatus[0]);
	waterbardec(currentbarstatus[1]);
	sleepbardec(currentbarstatus[4]);

	newstatus=status+inc;

	return newstatus;

}

int cleanbarinc(int status, int currentbarstatus[]) {

    int inc; //amount to increment
	int newstatus;

	// Read the image data into memory
	unsigned char * bufferPtr = readRAWImage( "bathroom.bmp", 54 ); //changes background to bathroom
	   
	// Draw the image on screen
	printRAWImage ( 0, 0, 800, 600, bufferPtr );

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//increment clean bar after cleaning
	   	 inc=144-(status);
			if (status+inc>=144) { //if bar value goes over 144, just set to 144
				gfx_rectangle(853, 83, 144, 14);
	   		}
		   	else if (status+inc<144 && status+inc>0.33*144) {
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, 144, 14); //fill up bar
			}
			else if (status+inc<0.33*144 && status+inc>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, 144, 14); //fill up bar
			}
	}

	newstatus=status+inc;

	return newstatus;

}

int sleepbarinc(int status, int currentbarstatus[]) {

   	int inc; //amount to increment
	int newstatus;

	//display pet sleeping
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//increment sleep bar after sleeping
	   	inc=144/10;
			if (status+inc>=144) { //if bar value goes over 144, just set to 144
				gfx_rectangle(853, 83, 144, 14);
	   		}
		   	else if (status+inc<144 && status+inc>0.33*144) {
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, inc+status, 14);
			}
			else if (status+inc<0.33*144 && status+inc>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, inc+status, 14);
			}
	}

	newstatus=status+inc;

	foodbardec(currentbarstatus[0]);
	waterbardec(currentbarstatus[1]);
	moodbardec(currentbarstatus[2]);

	return newstatus;

}

int foodbardec(int status) {

   	int dec; //amount to decrement
	int newstatus;
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//decrement food bar
	   	dec=144/10;
			if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, status-dec, 14);
			}
			else if (status-dec<0.33*144 && status-dec>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, status-dec, 14);
			}
	}

	newstatus=status-dec;

	return newstatus;

}	   	

int waterbardec(int status) {

   	int dec; //amount to decrement
	int newstatus;
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//decrement water bar
	   	dec=144/10;
			if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, status-dec, 14);
			}
			else if (status-dec<0.33*144 && status-dec>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, status-dec, 14);
			}
	}

	newstatus=status-dec;

	return newstatus;

}	   	

int moodbardec(int status) {

   	int dec; //amount to decrement
	int newstatus;
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//decrement mood bar
	   	dec=144/10;
			if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, status-dec, 14);
			}
			else if (status-dec<0.33*144 && status-dec>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, status-dec, 14);
			}
	}

	newstatus=status-dec;

	return newstatus;

}	   	

int cleanbardec(int status) {

   	int dec; //amount to decrement
	int newstatus;
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//decrement clean bar
	   	dec=144/10;
			if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, status-dec, 14);
			}
			else if (status-dec<0.33*144 && status-dec>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, status-dec, 14);
			}
	}

	newstatus=status-dec;

	return newstatus;

}	   	

int sleepbardec(int status) {

   	int dec; //amount to decrement
	int newstatus;
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//decrement sleep bar
	   	dec=144/10;
			if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
			   	gfx_cleararea(853, 83, status, 14);
	     	 	gfx_rectangle(853, 83, status-dec, 14);
			}
			else if (status-dec<0.33*144 && status-dec>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, status, 14);
			   	gfx_rectangle(853, 83, status-dec, 14);
			}
	}

	newstatus=status-dec;

	return newstatus;

}	   	









