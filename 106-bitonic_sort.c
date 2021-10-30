#include "sort.h"

<<<<<<< HEAD
/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * bitonic_merge - Merges the items in a sub-array based on a given order.
 * @array: The array to sort.
 * @size: The length of the array (should be a power of 2).
 * @low: The starting position of the sub-array.
 * @n: The length of the sub-array.
 * @ascending: A flag specifying the direction of the items in this sub-array.
 */
void bitonic_merge(int *array, size_t size,
									 size_t low, size_t n, char ascending)
{
	size_t i, m;

	if ((array != NULL) && (n > 1))
	{
		m = n / 2;
		for (i = low; i < (low + m); i++)
		{
			if ((array[i] > array[i + m]) == ascending)
			{
				swap_items(array, i, i + m);
			}
		}
		bitonic_merge(array, size, low, m, ascending);
		bitonic_merge(array, size, low + m, m, ascending);
=======
void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
	}
}

/**
<<<<<<< HEAD
 * bitonic_sort_split - Sorts a sub-array using the bitonic algorithm.
 * @array: The array to sort.
 * @size: The length of the array (should be a power of 2).
 * @low: The starting position of the sub-array.
 * @n: The length of the sub-array.
 * @ascending: A flag specifying the direction of the items in this sub-array.
 */
void bitonic_sort_split(int *array, size_t size,
												size_t low, size_t n, char ascending)
{
	size_t m;

	if ((array != NULL) && (n > 1))
	{
		m = n / 2;
		printf("Merging [%d/%d] (%s):\n",
					(int)(n), (int)size, ascending ? "UP" : "DOWN");
		print_array(array + low, n);
		bitonic_sort_split(array, size, low, m, TRUE);
		bitonic_sort_split(array, size, low + m, m, FALSE);
		bitonic_merge(array, size, low, n, ascending);
		printf("Result [%d/%d] (%s):\n",
					(int)(n), (int)size, ascending ? "UP" : "DOWN");
		print_array(array + low, n);
=======
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
	}
}

/**
<<<<<<< HEAD
 * bitonic_sort - Sorts an array using the bitonic sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array (should be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		bitonic_sort_split(array, size, 0, size, TRUE);
	}
=======
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
}
