#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter the values for a b c:");
	scanf("%d %d %d",&a,&b,&c);
	if(a>=b && a>=c){
		printf("A is greater");
	}	
	else if(b>=a && b>=c){
		printf("B is greater");
	}
	else
	{
		printf("c is greater");
	}
	return 0;
}
