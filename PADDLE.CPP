#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<bios.h>
#define right 19712
#define left 19200
#define up 18432
#define down 20480
#define esc 283
class ball
{       public:
	int x,y,dx,dy;
	ball()
	{
		x=random(640);
		y=random(480);
		dx=2;
		dy=2;
	}
void draw(int c)
{
	setcolor(c);
	circle(x,y,10);

}

void move(int a)
{
	switch(a){
		case left:x-=dx;break;
		case right:x+=dx;break;
		case up:y-=dx;break;
		case down:y+=dx;break;
	}
}

};

void main()
{       int key,key1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	randomize();
	ball b;
	while(key!=esc)
	{
		key1=bioskey(1);
		if(key1>0)
		key=bioskey(0);

	b.draw(WHITE);
	delay(10);
	b.draw(BLACK);
	b.move(key);
     }
closegraph();
}
