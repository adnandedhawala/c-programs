#include <stdio.h>
#include <graphics.h>
#include <float.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>
void main(){
 int gd=DETECT,gm;
 double dx=0.0,v=75.0,x=0.0,y=480.0,t=0.0,g=9.8,theta=80.0*3.1415/180;
 initgraph(&gd,&gm,"");
 while(!kbhit()){
  setcolor(WHITE);
  circle(x,y,10);
  delay(10);
  y=(v*sin(theta)*t)-(0.5*g*t*t);
  x=(v*cos(theta)*t)+dx;
  y=480-y;
  t=t+0.1;

  if(y>480){
   t=0;
   dx=x;
   v=0.5*v;
  }
 }
 closegraph();
}
