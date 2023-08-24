#include<stdio.h>
int main()
{
int a[100],b,c=0,i;
printf("enter the range :");
scanf("%d",&b);
for(i=0;i<b;i++)
{
scanf("%d",&a[i]);
c=c+a[i];
}
printf("the sum of number in the element is %d",c);
return  0;
}