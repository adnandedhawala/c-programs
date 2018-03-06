#include<float.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#define pi 3.142
void main()
{
int gd= DETECT, gm;
double tht=0.0, x=0.0, y=0.0, t=0.0, l=200.0, thz;
thz =(45*pi)/180;
initgraph (&gd, &gm, "");

while(!kbhit())
{
	tht = thz * cos(sqrt(9.8/l)*t);
	//printf("%f\n",tht);
	x= 320 +l*sin(tht);
	y= l*cos(tht);
	setcolor(WHITE);
	line(320,0,x,y-50);
	circle(x,y,50);
	delay(10);
	setcolor(BLACK);
	line(320,0,x,y-50);
	circle(x,y,50)  ;
	 t+=0.1;

	}

closegraph();
getch();

}