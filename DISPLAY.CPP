#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
while(!kbhit()){
       setcolor(WHITE);
       line(320,0,320,150);
       circle(320,200,50);
}
closegraph();
getch();


}