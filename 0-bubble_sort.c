#include "sort.h"
/**
 * bubble_sort - sorts an array of int using Bubble sort algorithm
 * @array: the array to perform the sort on
 * @size: the size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
unsigned int temp, i, j, flag;
if (!array || size == 0)
return;
temp = 0;
i = size - 1;
flag = 1;
while (flag)
{
flag = 0;
j = 0;
while (j < i)
{
if (array[j] > array[j + 1])
{
flag = 1;
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
j++;
}
i--;
}
}

