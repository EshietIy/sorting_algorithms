#include "sort.h"

<<<<<<< HEAD
/**
 * radix_sort - Sorts an array using the radix sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void radix_sort(int *array, size_t size)
{
	int digits = 0, i, j, max_val = 0, base = 10, pow_b;
	int *bins = NULL, *counts = NULL, sorted = FALSE;

	if ((array == NULL) || (size < 2))
		return;
	for (i = 0; i < (int)size; i++)
		max_val = array[i] > max_val ? array[i] : max_val;
	while (max_val > 0)
		digits++, max_val /= 10;
	bins = malloc(sizeof(int) * size);
	counts = malloc(sizeof(int) * base);
	digits = ((bins == NULL) || (counts == NULL) ? 0 : digits);
	for (i = 0, pow_b = 1; i < digits; i++, pow_b *= base)
	{
		for (j = 0; j < base; j++)
			counts[j] = 0;
		for (j = 0; j < (int)size; j++)
			counts[(array[j] / pow_b) % base]++;
		for (j = 1; j < base; j++)
			counts[j] += counts[j - 1];
		for (j = (int)size - 1; j >= 0; j--)
			bins[--counts[(array[j] / pow_b) % base]] = array[j];
		for (j = 0; j < (int)size; j++)
			array[j] = bins[j];
		print_array(array, size), sorted = TRUE;
	}
	if ((!max_val && !sorted) && (size > 0))
		print_array(array, size);
	if (bins != NULL)
		free(bins);
	if (counts != NULL)
		free(counts);
=======
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
}
