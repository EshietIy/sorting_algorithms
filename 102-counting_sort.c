#include "sort.h"

/**
<<<<<<< HEAD
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr = NULL, *array_sorted = NULL, max_val = 0;
	size_t i;

	if ((array == NULL) || (size < 2))
		return;
	for (i = 0; i < size; i++)
	{
		max_val = (array[i] > max_val ? array[i] : max_val);
		if (array[i] < 0)
			return;
	}
	count_arr = malloc(sizeof(int) * (max_val + 1));
	if (count_arr == NULL)
		return;
	array_sorted = malloc(sizeof(int) * size);
	if (array_sorted == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < (size_t)(max_val + 1); i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;
	for (i = 1; i < (size_t)(max_val + 1); i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, max_val + 1);
	for (i = size - 1; ; i--)
	{
		count_arr[array[i]]--;
		array_sorted[count_arr[array[i]]] = array[i];
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		array[i] = array_sorted[i];
	free(array_sorted), free(count_arr);
=======
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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
}
