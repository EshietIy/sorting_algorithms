#include "sort.h"
/**
 * swap_elements - swaps elements in an array
 * @array: array to swap on
 * @a: the first element
 * @b: the second element
 *
 */
void swap_elements(int *array, unsigned int a, unsigned int b)
{
int temp;

temp = array[a];
array[a] = array[b];
array[b] = temp;
}

/**
 * selection_sort - selection sort alogorithm
 * @array: the array sort
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
unsigned int i, j, min;
if (!array || size == 0 || size == 1)
return;
i = 0;
while (i < size - 1)
{
min = i;
j = i + 1;
while (j < size)
{
if (array[j] < array[min])
min = j;
j++;
}
if (min != i)
{
swap_elements(array, i, min);
print_array(array, size);
}
i++;
}
}
