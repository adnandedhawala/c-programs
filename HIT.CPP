#include <stdio.h>
#include <conio.h>
#include <bios.h>
#include <dos.h>
void main(){

 clrscr();
 int c,i;
 for(i=0;i<5;i++){
  printf("\nEnter a :-  ");
  c=bioskey(1);
  delay(100);
  printf("%d",c);
 }
}