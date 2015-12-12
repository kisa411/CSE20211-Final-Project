#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for 'usleep function'
#include "gfx5.c"
#include "gfxe.h"

void drawmenu();
void drawstatus();
int foodbarinc(int status); 
int waterbarinc(int status);
int moodbarinc(int status);
int cleanbarinc(int status);
int sleepbarinc(int status);
int foodbardec(int status); 
int waterbardec(int status);
int moodbardec(int status);
int cleanbardec(int status);
int sleepbardec(int status);
void initialbars();
void currentbars(int array[]);
int click(int xpos, int ypos);
//void balltoy(int array[]);

int main( int argc, char * argv[] ) {


	int xpos, ypos, loop=1, action;
	int currentbarstatus[5]={100, 100, 100, 100, 100}; //food, water, mood, clean, sleep
	int c;
	int new, newfood, newwater, newmood, newsleep, newclean;
	gfx_open(1050, 600, "TAMAGOTCHI - Borah & Emily");

	drawmenu();
	drawstatus();
	initialbars();
	
	// Read image data into memory
	unsigned char * bufferPtr = readRAWImage( "livingroom(light).bmp", 54 );
	unsigned char * pet = readRAWImage( "pet.bmp", 54 );
	unsigned char * foodbowl = readRAWImage( "dogfood.bmp", 54 );
	unsigned char * waterbowl = readRAWImage( "dogwater.bmp", 54 );
	unsigned char * toys = readRAWImage( "dogtoy.bmp", 54 );

					   


	     
	// Draw the initial living room on screen
	printRAWImage ( 0, 0, 800, 600, bufferPtr );
	free(bufferPtr);
  
	// Draw the image on screen
	printRAWImage ( 400, 500, 130, 130, pet );
	free( pet );

	while (loop) {

	   if (gfx_event_waiting()) {

		   c=gfx_wait();
		   gfx_wait();

		   if (c==1) {    //return for left click
			   xpos=gfx_xpos();
			   ypos=gfx_ypos();

			   action=click(xpos, ypos); 
			  
			switch (action) {
				case 1:
					//food
					//display food and pet eating
					
					// Go back to living room
				 
					// Draw the image on screen
					printRAWImage ( 0, 0, 800, 600, bufferPtr );
					//printf("livingroom\n");

					//draw pet
					printRAWImage ( 400, 500, 130, 130, pet );
					free( pet );
					   
					// Draw the image on screen
					printRAWImage ( 600, 500, 80, 80, foodbowl );
					free( foodbowl );

					//increment food bar by +20px each time it is clicked
					new=foodbarinc(currentbarstatus[0]);

					currentbarstatus[0] = new;
					if (new<=0) {
						gfx_clear();
						gfx_color(255, 0, 0);
						gfx_changefont("-itc-american typewriter-medium-r-normal--0-0-0-0-p-0-iso8859-16");
						gfx_text(400, 300, "YOUR PET DIED.\n");
						usleep(1000000);
						loop=0;
					}					
					break;
				case 2:
					//water
					
					// Go back to living room
				
					// Draw the image on screen
					printRAWImage ( 0, 0, 800, 600, bufferPtr );
					//printf("livingroom\n");
					
					// draw pet
					printRAWImage ( 400, 500, 130, 130, pet );
					free( pet );

					// Draw the image on screen
					printRAWImage ( 600, 500, 80, 80, waterbowl );
					free( waterbowl );


					//increment water bar by +20px each time it is clicked
					new=waterbarinc(currentbarstatus[1]);
					currentbarstatus[1] = new;
					if (new<=0) {
						gfx_clear();
						gfx_color(255, 0, 0);
						gfx_changefont("-itc-american typewriter-medium-r-normal--0-0-0-0-p-0-iso8859-16");
						gfx_text(400, 300, "YOUR PET DIED.\n");
						usleep(1000000);
						loop=0;
					
					}
					break;
				case 3:
					//play
					
					// Go back to living room
				
					// Draw the image on screen
					printRAWImage ( 0, 0, 800, 600, bufferPtr );
					//printf("livingroom\n");
				
					//draw pet
					printRAWImage ( 400, 500, 130, 130, pet );
					free( pet );
					   
					// Draw the image on screen
					printRAWImage ( 600, 500, 80, 80, toys );
					free( toys );


					//increment play bar by +20px each time it is clicked
					new=moodbarinc(currentbarstatus[2]);
					currentbarstatus[2] = new;
					// balltoy(currentbarstatus);

					//decrement food, water, and sleep by -20 px
					newfood = foodbardec(currentbarstatus[0]);
					currentbarstatus[0] = newfood;
					newwater = waterbardec(currentbarstatus[1]);
					currentbarstatus[1] = newwater;
					newsleep = sleepbardec(currentbarstatus[4]);
					currentbarstatus[4] = newsleep;
					newclean = cleanbardec(currentbarstatus[3]);
					currentbarstatus[3] = newclean;

					
					if (newfood==-1 || newwater==-1 || newsleep==-1) {
						gfx_clear();
						gfx_color(255, 0, 0);
						gfx_changefont("-itc-american typewriter-medium-r-normal--0-0-0-0-p-0-iso8859-16");
						gfx_text(400, 300, "YOUR PET DIED.\n");
						usleep(1000000);
						loop=0;

					}				
					break;
				case 4:
					//clean

					//draw bathroom
					//unsigned char *bathroom = readRAWImage("bathroom.bmp", 54);
					//printRAWImage (0, 0, 800, 600, bathroom);
					//free(bathroom);

					//draw pet
					printRAWImage ( 400, 500, 130, 130, pet );
					free( pet );

					//when cleaned, fill clean bar
					new=cleanbarinc(currentbarstatus[3]);
					currentbarstatus[3] = new;
					if (new<=0) {
						gfx_clear();
						gfx_color(255, 0, 0);
						gfx_changefont("-itc-american typewriter-medium-r-normal--0-0-0-0-p-0-iso8859-16");
						gfx_text(400, 300, "YOUR PET DIED.\n");
						usleep(1000000);
						loop=0;
					}
											
					break;
				case 5:
					//sleep
					//pet moves to bed and sleeps until user wakes it
					//food, water, and fun decreases

					// Go back to living room
					// change living room to dark - imitates turning off lights
					//unsigned char * dark = readRAWImage( "livingroom(dark).bmp", 54 );
	   
					// Draw the image on screen
					//printRAWImage ( 0, 0, 800, 600, dark );
					//free( dark );
					
					// draw pet
					printRAWImage ( 400, 500, 130, 130, pet );
					free( pet );

					//when sleep, fill sleep bar
					new = sleepbarinc(currentbarstatus[4]);
					currentbarstatus[4] = new;

					//decrement food, water, mood by -20px
					newfood = foodbardec(currentbarstatus[0]);
					currentbarstatus[0] = newfood;
					newwater = waterbardec(currentbarstatus[1]);
					currentbarstatus[1] = newwater;
					newmood = moodbardec(currentbarstatus[2]);
					currentbarstatus[2] = newmood;

					if (newfood==-1 || newwater==-1 || newmood==-1) {
						gfx_clear();
						gfx_color(255, 0, 0); //RED
						gfx_changefont("-itc-american typewriter-medium-r-normal--0-0-0-0-p-0-iso8859-16");
						gfx_text(400, 300, "YOUR PET DIED.\n");
						usleep(1000000);
						loop=0;
					}
	
					break;
				case 6:
					//quit
					loop=0;
			   }
		   }
	   }
   }
}


int click(int xpos, int ypos) {

	if (xpos>=837 && xpos<=837+84) {
		if (ypos>=381 && ypos <=381+57) {  //button 1: food
	   		return 1;
		}
		else if (ypos>=444 && ypos <=444+57) {  //button 3: play
			return 3;
		}
		else if (ypos>=507 && ypos <=507+57) {  //button 5: sleep
		   	return 5;
		}
	}
	else if (xpos>=929 && xpos<=929+84) { 
	   	if (ypos>=381 && ypos <=381+57) {   //button 2: water
			return 2;
		}
		else if (ypos>=444 && ypos <=444+57) {  //button 4: clean
			return 4;
		}
		else if (ypos>=507 && ypos <=507+57) {  //button 6: quit
		   	return 6;
		}
	}

	return 0;

}
	  
	
void drawmenu() {

	int w=gfx_textpixelwidth("MENU", "lucidasans-bold-18");
	float xpos;
	int a, b, c, d, e, f;
	unsigned char *food=readRAWImage("food.bmp", 54);
	unsigned char *water=readRAWImage("water.bmp", 54);
	unsigned char *quit=readRAWImage("quit.bmp", 54);
	unsigned char *play=readRAWImage("ball.bmp", 54);
	unsigned char *clean=readRAWImage("bubbles-hi.bmp", 54);
	unsigned char *sleep=readRAWImage("sleep1.bmp", 54);

	//big box
	gfx_color(102, 102, 255);
	gfx_fill_rectangle(830, 350, 190, 220);

	//icon images
	printRAWImage ( 837, 381, 84, 57, (char *) food );
	printRAWImage ( 929, 381, 84, 57, (char *) water );
	printRAWImage ( 929, 507, 84, 57, (char *) quit );
	printRAWImage ( 929, 444, 84, 57, (char *) play );
	printRAWImage ( 837, 444, 84, 57, (char *) clean );
	printRAWImage ( 837, 507, 84, 57, (char *) sleep );
 
	//label
	gfx_color(0, 0, 0);
	gfx_changefont("lucidasans-bold-18");
	xpos=830+((190-w)/2);
	gfx_text(xpos, 370, "MENU");
   
	//buttons
	//button boxes
	gfx_color(255, 255, 255);
	gfx_rectangle(837, 381, 84, 57); 
	gfx_rectangle(837, 444, 84, 57);
	gfx_rectangle(837, 507, 84, 57);	
	gfx_rectangle(929, 381, 84, 57);
	gfx_rectangle(929, 444, 84, 57); 
	gfx_rectangle(929, 507, 84, 57);

	//button icons
	gfx_changefont("lucidasans-bold-12");
	gfx_color(0,0,0);

	//food button
	a=gfx_textpixelwidth("FOOD", "lucidasans-bold-12");
	xpos=837+((84-a)/2);
	gfx_text(xpos, 381+16, "FOOD"); 

	//clean button
	b=gfx_textpixelwidth("PLAY", "lucidasans-bold-12");
	xpos=837+((84-b)/2);
	gfx_text(xpos, 444+16, "PLAY"); 

	//sleep button
	c=gfx_textpixelwidth("SLEEP", "lucidasans-bold-12");
	xpos=837+((84-c)/2);
	gfx_text(xpos, 507+16, "SLEEP");

	//water button
	d=gfx_textpixelwidth("WATER", "lucidasans-bold-12");
	gfx_color(0,0,0);
	xpos=929+((84-d)/2);
	gfx_text(xpos, 381+16, "WATER"); 

	//play button
	e=gfx_textpixelwidth("CLEAN", "lucidasans-bold-12");
	xpos=929+((84-e)/2);
	gfx_text(xpos, 444+16, "CLEAN"); 

	//quit button
	f=gfx_textpixelwidth("QUIT", "lucidasans-bold-12");
	xpos=929+((84-f)/2);
	gfx_text(xpos, 507+16, "QUIT"); 

	free( food );
	free( water );
	free( clean );
	free( sleep );
	free( quit );
	free( play );
}

void drawstatus() {

	int w=gfx_textpixelwidth("STATUS", "lucidasans-bold-18");
	int i;
	float xpos, ypos;
	char barnames[][6]={"FOOD", "WATER", "MOOD", "CLEAN", "SLEEP"};

	xpos=830+((190-w)/2);
	ypos=50;

	//draw box
	gfx_color(102, 102, 255);
	gfx_fill_rectangle(830, 30, 190, 290);

	//label
	gfx_color(0, 0, 0);
	gfx_changefont("lucidasans-bold-18");
	gfx_text(xpos, ypos, "STATUS");

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
   		gfx_fill_rectangle(853, 83+(50*i), 100, 14); //bar is 100 px long
   }

}

void currentbars(int current[]) {

   	int i, status=.33*144;

	for (i=0; i<5; i++) {
		if (current[i]<=status) {
			gfx_color(255, 51, 51); //red
			gfx_fill_rectangle(853, 83+(50*i), current[i], 14);
		}
		else {
			gfx_color(51, 255, 255); //blue 
			gfx_fill_rectangle(853, 83+(50*i), current[i], 14);
		}
	}
}



int foodbarinc(int status) {

   	int inc; //amount to increment

	//display pet eating
	

	gfx_color(51, 255, 255);  //blue

	if (status<=0) {   //pet dies if bar reaches 0   we dont need this!
	   	gfx_cleararea(853, 83, 144, 14);
		return 0; //?
	}
	else {
	   	//increment food bar after eating
	   	inc=144/10;
			if (status+inc>=144) { //if bar value goes over 144, just set to 144
				gfx_fill_rectangle(853, 83, 144, 14);
				return 144;
	   		}
		   	else if (status+inc<144 && status+inc>0.33*144) {
			   	gfx_cleararea(853, 83, 144, 14);
	     	 		gfx_fill_rectangle(853, 83, inc+status, 14);
				return status+inc;
			}
			else if (status+inc<0.33*144 && status+inc>0) {
			   	gfx_color(255, 51, 51);   //red
			   	gfx_cleararea(853, 83, 144, 14);
			   	gfx_fill_rectangle(853, 83, inc+status, 14);
				return status+inc;
			}
	}

}

int waterbarinc(int status) {

   	int inc; //amount to increment

	//display pet drinking
	

	gfx_color(51, 255, 255);  //blue


        //increment water bar after eating
        inc=144/10;
	if (status+inc>=144) { //if bar value goes over 144, just set to 144
		gfx_fill_rectangle(853, 133, 144, 14);
		return 144;
	 }
	else if (status+inc<144 && status+inc>0.33*144) {
		gfx_cleararea(853, 133, 144, 14);
		gfx_fill_rectangle(853, 133, inc+status, 14);
		return status+inc;

	}
	else if (status+inc<0.33*144 && status+inc>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 133, 144, 14);
		gfx_fill_rectangle(853, 133, inc+status, 14);
		return -1;
	}
}



int moodbarinc(int status) {

   	int inc; //amount to increment

	//display pet playing
	

	gfx_color(51, 255, 255);  //blue
        
	//increment mood bar after playing
	inc=144/10;
	if (status+inc>=144) { //if bar value goes over 144, just set to 144
	  gfx_fill_rectangle(853, 183, 144, 14);
	  return 144;
	}
	else if (status+inc<144 && status+inc>0.33*144) {
	  gfx_cleararea(853, 183, 144, 14);
	  gfx_fill_rectangle(853, 183, inc+status, 14);
	  return status+inc;
	}
	else if (status+inc<0.33*144 && status+inc>0) {
	  gfx_color(255, 51, 51);   //red
	  gfx_cleararea(853, 183, 144, 14);
	  gfx_fill_rectangle(853, 183, inc+status, 14);
	  return status+inc;
	}

}

// void balltoy(int currentbarstatus[]) {

// 	//ball toy bouncing around screen
// 	double x, y, dx, dy;
// 	char c = '0';


// 	//do random direction 
// 	do {
// 		drawmenu();
// 		currentbars(currentbarstatus);

// 		// Read the image data into memory
// 		//unsigned char * bufferPtr = readRAWImage( "livingroom(light).bmp", 54 );
	   
// 		// Draw the image on screen
// 		//printRAWImage ( 0, 0, 800, 600, (char *) bufferPtr );

// 		//draw pet
// 		// unsigned char * pet = readRAWImage( "pet.bmp", 54 );
		   
// 		// Draw the image on screen
// 		// printRAWImage ( 400, 500, 130, 130, pet );
// 		// free( pet );

	
// 		gfx_color(255, 255, 0);

// 		gfx_fill_circle(x, y, 20); //draw circle while changing its coordinates by specified random amount
// 		x += dx;
// 		y += dy;

// 		gfx_flush(); //after you draw everything you want, ensures that it makes it show onto the screen

// 		usleep(5000); //makes image stay on screen for specified milliseconds

// 		gfx_clear(); //clear screen of previous animations

// 		if (x > 780) { //x-boundaries of graphics window
// 			x = 780;
// 			dx = -dx; //re-set location of circle
// 		} else if (x < 20) {
// 			x = 20;
// 			dx = -dx;
// 		} else if (y > 580) {
// 			y = 580;
// 			dy = -dy;
// 		} else if (y < 20) { //y-boundaries of graphics window
// 			y = 20;
// 			dy = -dy;
// 		}	

// 		if (c == 1) {
// 			x = gfx_xpos(); //get mouse location
// 			y = gfx_ypos(); //get mouse location

// 			dx = rand()%3; //randomly changes speed of circle
// 			dy = rand()%3; //randomly changes speed of circle

// 			c = '0';	
// 		}	

// 		if (gfx_event_waiting()) {
// 			c = gfx_wait(); //repeat loop until user clicks mouse
// 		}	
// 	} while (c != 'q'); //do-while 

// }


int cleanbarinc(int status) {

   	int inc; //amount to increment

	// Read the image data into memory
	unsigned char *bathroom = readRAWImage( "bathroom.bmp", 54 ); //changes background to bathroom
	//printf("bathroom\n"); 
	// Draw the image on screen
	printRAWImage ( 0, 0, 800, 600, bathroom);

	gfx_color(51, 255, 255);  //blue


	//increment clean bar after cleaning
	inc=144-(status);
	if (status+inc>=144) { //if bar value goes over 144, just set to 144
		gfx_fill_rectangle(853, 233, 144, 14);
		return 144;
	}
	else if (status+inc<144 && status+inc>0.33*144) {
		gfx_cleararea(853, 233, 144, 14);
		gfx_fill_rectangle(853, 233, 144, 14); //fill up bar
		return status+inc;
	}
	else if (status+inc<0.33*144 && status+inc>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 233, 144, 14);
		gfx_fill_rectangle(853, 233, 144, 14); //fill up bar
		return status+inc;
	}

}

int sleepbarinc(int status) {

   	int inc; //amount to increment

	//display pet sleeping
	
	gfx_color(51, 255, 255);  //blue

	
	//fill up sleep bar after sleeping
	inc=144-(status);
	if (status+inc>=144) { //if bar value goes over 144, just set to 144
		gfx_fill_rectangle(853, 283, 144, 14);
		return 144;
	}
	else if (status+inc<144 && status+inc>0.33*144) {
		gfx_cleararea(853, 283, 144, 14);
		gfx_fill_rectangle(853, 283, 144, 14); //fill up bar
		return status+inc;
	}
	else if (status+inc<0.33*144 && status+inc>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 283, 144, 14);
		gfx_fill_rectangle(853, 283, 144, 14); //fill up bar
		return status+inc;
	}

}

int foodbardec(int status) {

   	int dec; //amount to decrement

	gfx_color(51, 255, 255);  //blue

		
	//decrement food bar
	dec=144/10;
	if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
		gfx_cleararea(853, 83, 144, 14);
		gfx_fill_rectangle(853, 83, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<0.33*144 && status-dec>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 83, 144, 14);
		gfx_fill_rectangle(853, 83, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<=0) {
		return -1;
	}

}	   	

int waterbardec(int status) {

   	int dec; //amount to decrement
	

	gfx_color(51, 255, 255);  //blue

	//decrement water bar
	dec=144/10;
	if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
		gfx_cleararea(853, 133, 144, 14);
		gfx_fill_rectangle(853, 133, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<0.33*144 && status-dec>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 133, 144, 14);
		gfx_fill_rectangle(853, 133, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<=0) {
		return -1;
	}

	}


int moodbardec(int status) {

   	int dec; //amount to decrement

	gfx_color(51, 255, 255);  //blue


	//decrement mood bar
	dec=144/10;
	if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
		gfx_cleararea(853, 183, 144, 14);
		gfx_fill_rectangle(853, 183, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<0.33*144 && status-dec>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 183, 144, 14);
		gfx_fill_rectangle(853, 183, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<=0) {
		return -1;
	}

}	   	

int cleanbardec(int status) {

   	int dec; //amount to decrement

	gfx_color(51, 255, 255);  //blue

	//decrement clean bar
	dec=144/10;
	
	if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
		gfx_cleararea(853, 233, 144, 14);
		gfx_fill_rectangle(853, 233, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<0.33*144 && status-dec>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 233, 144, 14);
		gfx_fill_rectangle(853, 233, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<=0) {
		return -1;
	}

}
   	

int sleepbardec(int status) {

   	int dec; //amount to decrement

	gfx_color(51, 255, 255);  //blue

	//decrement sleep bar
	dec=144/10;
	if (status-dec<144 && status-dec>0.33*144) { //redraw bar if decremented
		gfx_cleararea(853, 283, 144, 14);
		gfx_fill_rectangle(853, 283, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<0.33*144 && status-dec>0) {
		gfx_color(255, 51, 51);   //red
		gfx_cleararea(853, 283, 144, 14);
		gfx_fill_rectangle(853, 283, status-dec, 14);
		return status-dec;
	}
	else if (status-dec<=0) {
		return -1;
	}

}	   	









