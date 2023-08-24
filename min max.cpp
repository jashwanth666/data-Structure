#include<iostream>
using namespace std;
int main()
{
int a[100],b[100],c[100],n,i,j;
cout<<"Enter the range for first array";
cin>>n;
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
if(a[i]>a[j])
{
int temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
cout<<endl<<"the difference between min and max term is "<<a[n-1]-a[0];
}