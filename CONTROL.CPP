#include<stdio.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#define esc 283
#define left 19200
#define right 19712
void main(){
 int key,key1;
 while(key!=esc){
   key1=bioskey(1);
   if(key1>0)
  key= bioskey(0);
  printf("%d \n",key);
  delay(1000);
 }
}