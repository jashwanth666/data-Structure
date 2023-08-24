#include <stdio.h>
int main() 
{
int a;
printf("Enter the range");
scanf("%d", &a);
int n1 = 0,n2 = 1;
printf("Fibonacci Series: ");
for (int i = 0; i < a; i++) 
{
printf("%d ",n1);
int next = n1 + n2;
n1 = n2;
n2= next;
}
return 0;
}