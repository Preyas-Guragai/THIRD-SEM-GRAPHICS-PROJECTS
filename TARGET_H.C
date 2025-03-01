#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<time.h>

#define MAX_TARGETS 5

struct target{
int x,y;       //position
int radius     //size
int speed;    //movement speed
int active;
};

int main()
    {
    int gd=DETECT,gm;
    int maxx, maxy;
    int score=0;
    int i;
    int crosshairX, crosshairY;
    initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");

    maxx=getmaxx();
    maxy=getmaxy();
    score=0;
    crosshairX=maxx/2;
    crosshairY=maxy/2;

    struct target targets[MAX_TARGET];
    srand (time(null)); // seed random number


    for(i=0; i<MAX_TARGETS; i++)
    {
    targets[i].x=rand() %(maxx-50);
     targets[i].y=rand() %(maxx-50);
      targets[i].radius=10_rand()%20;
      targets[i].speed=2+rand()%3;
      targets[i].active=1

    //note: rand() generates random value. any number divided by some number.
       // lets say 10%3 will always have remainder less than 3. if x%20, the
	      // remainder is any value but always less than 20

