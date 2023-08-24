#include <stdio.h>
int partition(int arr[], int low, int high) 
{
int pivot = arr[high];
int i = low - 1;
for (int j = low; j <= high - 1; j++) 
{
if (arr[j] < pivot) 
{
i++;
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
int temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;
return i + 1;
}
void quickSort(int arr[], int low, int high) 
{
if (low < high) 
{
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main() 
{
int size;
printf("Enter the number of elements: ");
scanf("%d", &size);
int arr[size];
printf("Enter the elements:\n");
for (int i = 0; i < size; i++) 
{
scanf("%d", &arr[i]);
}
printf("Original Array: ");
for (int i = 0; i < size; i++) 
{
printf("%d ", arr[i]);
}
printf("\n");
quickSort(arr, 0, size - 1);
printf("Sorted Array: ");
for (int i = 0; i < size; i++) 
{
printf("%d ", arr[i]);
}
printf("\n");

return 0;
}