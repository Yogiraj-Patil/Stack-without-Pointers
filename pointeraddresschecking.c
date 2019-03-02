#include<stdio.h>
#define end }
int main(){

int a[] ={65,66,67,68} ;
char *p = &a;
p+=2;
printf("%d",*p);// ans is:- 0
end
