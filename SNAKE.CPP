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
class snake {
	public:
	int x,y,oldx,oldy;

void draw(int c){
	setcolor(c);
	rectangle(x,y,x+10,y+10);

	}
};
class fruit{
	public:
	int x,y,hit;
	fruit(){
	x=random(640);
	y=random(480);
	hit=0;
	}
	void draw(int c){
		setcolor(c);
		circle(x,y,10);

    }
};

void main(){
int gd=DETECT,gm,NumVis=1,i,key,key1;
snake s[10];
randomize();
fruit f[5];
initgraph (&gd,&gm,"");

s[0].x=320;
s[0].y=240;
s[0].oldx=s[0].x;
s[0].oldy=s[0].y;

for(i=1;i<10;i++){
	  s[i].x=s[i-1].x+10;
	  s[i].y=s[i-1].y ;
	  s[i].oldx=s[i].x;
	  s[i].oldy=s[i].y;
}
while(key!=esc){
	key1=bioskey(1);
	if(key1>0)key=bioskey(0);

	for(i=0;i<NumVis;i++)s[i].draw(WHITE);
H
	for(i=0;i<5;i++){
	       if(f[i].hit==0){
			f[i].draw(RED);
			//printf("a");
		}

	}


	delay(50);

	for(i=0;i<NumVis;i++)s[i].draw(BLACK);

	for(i=0;i<5;i++){
			f[i].draw(BLACK);

	}


	s[0].oldx=s[0].x;
	s[0].oldy=s[0].y;

	if(key==left)s[0].x-=10;
	if(key==right)s[0].x+=10;
	if(key==up)s[0].y-=10;
	if(key==down)s[0].y+=10;
	if(s[0].x>=630)s[0].x=630;
	if(s[0].x<=0)s[0].x=0;
	if(s[0].y>=470)s[0].y=470;
	if(s[0].y<=0)s[0].y=0;


	//shuffle logic

	for (i=1;i<NumVis;i++){
	 s[i].oldx=s[i].x;
	 s[i].oldy=s[i].y;
	 s[i].x=s[i-1].oldx;
	 s[i].y=s[i-1].oldy;
	}
	//collision logic
	for(int i=0;i<5;i++){
		if(f[i].hit==1)
		continue;
		if(abs(s[0].x-f[i].x)<=20 && abs(s[0].y-f[i].y)<=20)
		{
		f[i].hit=1;
		//printf("Hit");
		NumVis++;
		}

	}



}
closegraph();
}