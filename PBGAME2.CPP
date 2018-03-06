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
		y=200;
		dx=2;
		dy=2;
	}
void draw(int c)
{
	setcolor(c);
	circle(x,y,10);

}

void move()
{
	x+=dx;
	y+=dy;
	if(x>640||x<0)dx=-dx;
	if(y<0)dy=-dy;
}

};
class paddle
{       public:
	int px,py,pdx;

	paddle()
	{
	  pdx=4;
	}

void draw(int c)
{
	setcolor(c);
	rectangle(px,py,px+100,py+10);
	delay(10);

}
void move(int key)
{
	if(key==left)px-=pdx;
	if(px<0)px=0;
	if(key==right)px+=pdx;
	if(px>540)px=540;
}
};

main()
{       int key,key1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	randomize();
	ball b;
	paddle p[2];
	p[1].px=320,p[0].px=320,p[1].py=30,p[0].py=470;
	while(key!=esc)
	{
		key1=bioskey(1);
		if(key1>0)
		key=bioskey(0);

	b.draw(WHITE);
	p[0].draw(WHITE);
	p[1].draw(WHITE);
	delay(10);
	b.draw(BLACK);
	p[0].draw(BLACK);
	p[1].draw(BLACK);
	b.move();
	p[0].move(key);
	p[1].move(key);
	if(((b.x>=p[0].px&&b.x<=p[0].px+100)&&(b.y>=p[0].py-10&&b.y<=p[0].py+10))||((b.x>=p[1].px&&b.x<=p[1].px+100)&&(b.y>=p[1].py&&b.y<=p[1].py+20)))
	{
		b.dy=-b.dy;
		b.dx++;
		b.dy++;
	}
       if(b.y>=470||b.y<=0)
       {
	settextstyle(2,0,10);
	setcolor(WHITE);
	outtextxy(30,200,"GAME OVER MOFO");
	getch();
	break;

       }
     }
closegraph();
}

