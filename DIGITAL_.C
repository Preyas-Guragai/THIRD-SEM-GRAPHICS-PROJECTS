       #include<conio.h>
       #include<stdio.h>
       #include<dos.h>
       #include<graphics.h>
       #include<time.h>

       void  main()
       {
       int gd= DETECT, gm;
       char timeStr[9]; //[hh:mm:ss]
       struct time t;
       initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");

       setbkcolor(BLACK);
       setcolor(GREEN);
       settextstyle(DEFAULT_FONT, 0,5);
       //settextstyle(DEFAULT_FONT, HORZ_DIR, size_of_text)
       //HORZ_DIR is not recognized by my compiler so use its corresponding value

       while(!kbhit()) // run until a key is pressed
       {
       gettime(&t); //get current time;

       //format time string(hh.mm.ss)
       sprintf(timeStr,"%02d:%02d:%02d", t.ti_hour, t.ti_min, t.ti_sec);

       //clear previous time display
       cleardevice();
	 //display time at the centre of screen
       outtextxy(getmaxx()/2-100, getmaxy()/2-20, timeStr);

			   delay(1000);
			   }
			   closegraph();
			   restorecrtmode();
			   }