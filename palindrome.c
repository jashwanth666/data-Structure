#include<stdio.h>
#include<string.h>
int main()
{
int k,i,length;
char a[100];
printf("enter the word");
scanf("%c",&a);
length=strlen(a);
for(i=0;i<length;i++)
{
if(a[i]==a[length-i-1])
{
k=1;
}
else
{
k=0;

}
}
if(k=1)
{
printf("the given word is palindrome");
}
else
{
printf("the given word is not palindrome");
}
}