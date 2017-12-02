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

void lmain()
{
	// STARTING PAGE
	int gd=DETECT,gm,i,j;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setbkcolor(0);
	setbkcolor(BLUE);
	setcolor(WHITE);
	line(110,65,505,65);
	line(115,70,500,70);
	line(120,75,495,75);
	line(120,75,120,345);
	line(115,70,115,350);
	line(110,65,110,355);
	line(110,355,505,355);
	line(115,350,500,350);
	line(120,345,495,345);
	line(505,65,505,355);
	line(500,70,500,350);
	line(495,75,495,345);

}