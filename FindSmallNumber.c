#include<stdio.h>
int main()
{
  // Find the smallest number from the given number
long num;
printf("Enter the number :");
scanf("%ld",&num);
int min=num%10;
while(0<num)
{
if(min>num%10)
{
min=num%10;
num=num/10;
}
else
{
num=num/10;
}
}
printf("\nSmall Number Is :%d \n",min);
}
