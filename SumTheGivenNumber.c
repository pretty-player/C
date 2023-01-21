#include<stdio.h>
int main()
{
    long num;
    int val=0;
    printf("Enter The Number :");
    scanf("%ld",&num);
    while(num>0)
    {
        val+=num%10;
        num/=10;
    }
    printf("Sum of digit is :%d\n",val);
    return 0;
}
