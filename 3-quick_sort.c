#include "sort.h"

/**
 * partition - partition algorithm
 * @array: the array
 * @low: the index of the partition wall
 * @high: the index of the pivot
 * @size: size of array in int
 *Return: returns the location to place the pivot
 *
 */
unsigned int partition(int *array, int low, int high, size_t size)
{
int x, y, temp;
int pivot;

x = low - 1;
pivot = array[high];

for (y = low; y <= high - 1; y++)
{
if (array[y] <= pivot)
{
x++;
if (x != y)
{
temp = array[x];
array[x] = array[y];
array[y] = temp;
print_array(array, size);
}
}
}
temp = array[x + 1];
array[x + 1] = array[high];
array[high] = temp;
print_array(array, size);
return (x + 1);
}

/**
 * qs_function - actual quick sort alogorithm
 * @array: the array
 * @lo: the low index
 * @hi: the high index
 * @size: size of array in int
 */
void qs_function(int *array, unsigned int lo, unsigned int hi, size_t size)
{
int p;
if (lo < hi)
{
p = partition(array, lo, hi, size);
qs_function(array, lo, p - 1, size);
qs_function(array, p + 1, hi, size);
}
}

/**
 * quick_sort - implementing the quick sort algorithm
 * @array: the array
 * @size: size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
qs_function(array, 0, size - 1, size);
}
