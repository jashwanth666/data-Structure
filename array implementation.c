#include <stdio.h>
#define MAX_SIZE 100
int main() {
int arr[MAX_SIZE];
int size = 0;
void insert(int element, int position) 
{
if (size >= MAX_SIZE) 
{
printf("Array is full, cannot insert.\n");
return;
}
if (position < 0 || position > size) 
{
printf("Invalid position for insertion.\n");
return;
}
for (int i = size; i > position; i--) 
{
arr[i] = arr[i - 1];
}
arr[position] = element;
size++;
}
void delete(int position) 
{
if (size <= 0) 
{
printf("Array is empty, cannot delete.\n");
return;
}
if (position < 0 || position >= size) 
{
printf("Invalid position for deletion.\n");
return;
}
for (int i = position; i < (size - 1); i++) 
{
arr[i] = arr[i + 1];
}
size--;
}
void display() 
{
if (size <= 0) 
{
printf("Array is empty.\n");
return;
}
printf("Array elements: ");
for (int i = 0; i < size; i++) 
{
printf("%d ", arr[i]);
}
printf("\n");
}
insert(10, 0);
insert(20, 1);
insert(30, 2);
display();
delete(1);
display();
return 0;
}
