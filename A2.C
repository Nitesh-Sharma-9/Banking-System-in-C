//#include<iostream.h>
#include<conio.h>
#include<dos.h>
//#include<iomanip.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>
//#include<fstream.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
void gmain()
{
int gd=DETECT,gm,i,j;
clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setbkcolor(0);
	delay(100);
	setcolor(RED);
	settextstyle(8,0,4);
	outtextxy(230,50,"WELCOME"); delay(1000);
	settextstyle(8,0,4);
	setcolor(BLUE);
	outtextxy(290,150,"TO"); delay(1000);
	settextstyle(8,0,3);
	setcolor(GREEN);
	outtextxy(180,250,"INTERNATIONAL BANK"); //delay(1000);
	setcolor(WHITE);
	settextstyle(8,0,4);
	for(i=-225,j=639;i<100;i++,j--)
	{
	  outtextxy(i,360,"MADE BY:-"); outtextxy(j,360,"NITESH SHARMA");
	  delay(15); setcolor(BLACK);
	  outtextxy(i,360,"MADE BY:-"); outtextxy(j,360,"NITESH SHARMA");
	  setcolor(WHITE);
	}
	outtextxy(100,360,"MADE BY:-");
	outtextxy(j,360,"NITESH SHARMA"); delay(100);
	i=1;
	setbkcolor(BLACK);
	do
	{
	  setcolor(i);
	  settextstyle(8,0,4);
	  outtextxy(230,50,"WELCOME"); delay(100);
	  settextstyle(8,0,4);
	  setcolor(i+1);
	  outtextxy(290,150,"TO"); delay(100);
	  settextstyle(8,0,3);
	  setcolor(i+2);
	  outtextxy(180,250,"INTERNATIONAL BANK"); delay(100);
	  setcolor(i+3);
	  settextstyle(8,0,4);
	  outtextxy(100,360,"MADE BY:-");
	  outtextxy(j,360,"NITESH SHARMA"); delay(100);
	  i++;
	} while(i!=13);
	delay(100); cleardevice();
	settextstyle(0,0,0);
	for(i=400;i>=0;i--) { setcolor(BLUE); circle(320,240,i); delay(5); }
	for(i=0;i<=400;i++) { setcolor(RED); circle(320,240,i); delay(5); }
	// MAP SHOWING TOP VIEW OF THE HOTEL
	cleardevice();
	closegraph();
	//setbkcolor(BLACK);
	//setcolor(WHITE);

}