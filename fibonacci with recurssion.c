#include <stdio.h>
int main() 
{
int num;
printf("Enter the number of terms in Fibonacci series: ");
scanf("%d",&num);
int n1=0,n2=1;
printf("Fibonacci Series: ");
for (int i=0;i<num;i++) 
{
printf("%d ",n1);
int next=n1+n2;
n1=n2;
n2 =next;
}
return 0;
}
