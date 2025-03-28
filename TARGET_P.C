#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<graphics.h>
#include<stdlib.h>
#include<stddef.h>

#define MAX_TARGETS 5

struct target{
int x,y;       //position
int radius;     //size
int speed;    //movement speed
int active;

};

int main()
    {
    int gd =DETECT, gm;

    int maxx, maxy;
    int score=0;
    int i;
    struct target targets[MAX_TARGETS];
    int crosshairX, crosshairY;
    char key;
    char scoreText[20]; //for displaying score
    int dx, dy;
    int distance;
    int running=1;

    initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");

    maxx=getmaxx();
    maxy=getmaxy();
    score=0;
    crosshairX=maxx/2;
    crosshairY=maxy/2;


    srand(time(NULL)); // seed random number


    for(i=0; i<MAX_TARGETS; i++)
    {
    targets[i].x=rand() %(maxx-50);
     targets[i].y=rand() %(maxx-50);
      targets[i].radius=10+rand()%20;
      targets[i].speed=2+rand()%2;
      targets[i].active=1;

    //note: rand() generates random value. any number divided by some number.
       // lets say 10%3 will always have remainder less than 3. if x%20, the
	      // remainder is any value but always less than 20
       }

       while(running) //exit on key press,
       // kbhit returns 0 if no key pressesd and returns 1  if key is pressed
       {
       cleardevice();

       //moving target

	  for(i=0; i<MAX_TARGETS; i++)

	       {
		  if(targets[i].active)
		    {
		       setcolor(RED);
		       circle(targets[i].x, targets[i].y, targets[i].radius) ;
		       targets[i].x +=targets[i].speed;

		       //in case if target goes out of raster
		       if(targets[i].x>maxx)
		       {
		       targets[i].x=-targets[i].radius;
		       targets[i].y=rand()%(maxy-50);
		       targets[i].speed=2+rand()%2;

		       }
		  }
	       }

	       //draw crosshair in the screen.
	       setcolor(WHITE);
	       line(crosshairX-10, crosshairY, crosshairX+10, crosshairY);  //horizontal line
	       line(crosshairX, crosshairY-10, crosshairX, crosshairY+10);  //verticle line

	       sprintf(scoreText," score: %d", score);
	       setcolor(YELLOW);
	       outtextxy(10,10, scoreText);

	       //keyboard input

	       if(kbhit())
	       {
	       key=getch();

	       switch(key)
	       {
		  case 'w':
		  if(crosshairY>10)
		  {
		  crosshairY-=10;
		  break;
		  }


		  case 's':
		  if(crosshairY<maxy-10)
		  {
		  crosshairY+=10;
		  break;
		  }

		  case 'a':
		  if(crosshairX>10)
		  {
		  crosshairX-=10;
		  break;
		  }

		  case 'd':
		  if(crosshairX<maxx-10)
		  {
		  crosshairX+=10;
		  break;
		  }

		  case ' ':
		    for(i=0; i<MAX_TARGETS; i++)
		    {
		      if(targets[i].active)
		       {
			dx=targets[i].x-crosshairX;
			dy=targets[i].y-crosshairY;
			distance =sqrt(dx*dx+dy*dy);
			if(distance<=targets[i].radius)
			{
			 targets[i].active=0;
			 score+=10;
			 targets[i].x= -targets[i].radius;
			 targets[i].y=rand()%(maxy-50);
			 targets[i].speed=2+rand()%3;
			 targets[i].active=1;
			}
		    }
	  }
	  break;
	  case 27:
	  running=0;
	  break;

	  }
       }

   delay(50);
   }
   getch();
   closegraph();
   printf("final score: %d\n", score);
   return 0;
   }