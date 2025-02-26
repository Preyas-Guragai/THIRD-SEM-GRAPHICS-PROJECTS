       #include<conio.h>
       #include<stdio.h>
       #include<dos.h>
       #include<graphics.h>

       #define true 1
       #define false 0
       void drawcar(int x, int y)
       {
       setcolor(RED);
       rectangle(x, y, x+50, y+30);
       }

       void drawRoad()
       {
       int i;
       setcolor(WHITE);
	  for(i=0; i<480; i+=50)
	    {
	    line(0, i, 640, i);
	    }
       }





       int main()
       {
       int gd= DETECT, gm;
       int carX, carY, roadX, roadY;
       initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");

       carX = 300,
       carY = 400;

       while(true)
       {
       drawroad();

       drawcar( carX, carY);

       if(kbhit())
       {
       char ch=getch();
       if(ch==27) //escape key
       break;

       if(ch==75)// left arrow key
       carX-=10;

       if(ch==77) //right
       car