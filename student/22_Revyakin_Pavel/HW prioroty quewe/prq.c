#include <stdio.h>
static int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("В очереди 1 элемент");
  }
  else
  {
    int least = i;
    int left =2 * i + 1;
    int right =2 * i + 2;
    if (left < size && array[left] < array[least])
      least = left;
    if (right < size && array[right] < array[least])
      least = right;
    if (least != i)
    {
      swap(&array[i], &array[least]);
      heapify(array, size, least);
    }
  }
}
void insert(int array[],int newNum,int sizem)
{
  if (size>sizem){
      return;
  } 
  if (size == 0)
  {
    array[0] = newNum;
    size ++;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }
  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
void printhigher(int array[]){
	printf("%d",array[0]);
}
int main()
{
  int element;
  int choose;
  int size_of_array;
  printf("Размер массива n (0...n)\n");
  scanf("%d",&size_of_array);
  int array[size_of_array];
  printf("1.Ввод элемента \n 2.Вывести коренной элемент\n 3.Удлаление элемента \n 4.Печать\n ");
  scanf("%d",&choose);
  while(1){
  switch(choose)
  {
    case 1:
        printf("Введите элемент");
        scanf("%d",&element);
        insert(array, element, size_of_array);
        break;
    case 2:
  	    printhigher(array);
        break;
    case 3:
        printf("Введите элемент");
        scanf("%d",&element);
        deleteRoot(array, element);
        break;
	case 4:
		printArray(array, size);
	    break;	
  }
  scanf("%d",&choose);
}
}
