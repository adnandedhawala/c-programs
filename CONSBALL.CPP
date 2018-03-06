#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
class ball{
public:
int x,dx,dy,y;
ball(){
	x= random(640);
	y= random(480);
	dx=1;
	dy=1;
       //printf("inc");
	}
void move(){
       x+=dx;
       y+=dy;
       if(x>640||x<0)dx=-dx;
       if(y>480||y<0)dy=-dy;
       }
void draw(int c){
	setcolor(c);
	circle(x,y,5);
	}
~ball(){
	printf("end\n");
	}
};
void main(){
int gd= DETECT, gm;
initgraph(&gd, &gm,"");
ball b[10];
int i;
while(!kbhit()){
	for(i=0;i<10;i++){
		b[i].draw(RED);
		}
	delay(10);
	for(i=0;i<10;i++){

		b[i].draw(BLACK);
		}
	for(i=0;i<10;i++){
		b[i].move();
		}
	}
closegraph();
}