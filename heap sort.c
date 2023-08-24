#include <stdio.h>
int main() 
{
int arr[] = {12, 11, 13, 5, 6, 7};
int n = sizeof(arr) / sizeof(arr[0]);
for (int i = n / 2 - 1; i >= 0; i--) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])
largest = left;
if (right < n && arr[right] > arr[largest])
largest = right;
if (largest != i) {
int temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;
int sub_largest = largest;
while (sub_largest < n) {
int l = 2 * sub_largest + 1;
int r = 2 * sub_largest + 2;
int largest = sub_largest;
if (l < n && arr[l] > arr[largest])
largest = l;
if (r < n && arr[r] > arr[largest])
largest = r;
if (largest != sub_largest) {
int temp = arr[sub_largest];
arr[sub_largest] = arr[largest];
arr[largest] = temp;
sub_largest = largest;
} else {
break;
}
}
}
}
for (int i = n - 1; i > 0; i--) {
int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
int largest = 0;
int sub_largest;
while (largest < i) {
int l = 2 * largest + 1;
int r = 2 * largest + 2;
sub_largest = largest;
if (l < i && arr[l] > arr[sub_largest])
sub_largest = l;
if (r < i && arr[r] > arr[sub_largest])
sub_largest = r;
if(sub_largest != largest) 
{
int temp = arr[largest];
arr[largest] = arr[sub_largest];
arr[sub_largest] = temp;
largest = sub_largest;
} 
else 
{
break;
}
}
}
printf("Sorted array: ");
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
return 0;
}
