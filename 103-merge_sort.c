#include "sort.h"

<<<<<<< HEAD
/**
 * top_down_merge - Merges an array that has been split using the
 * top-down approach.
 * @array: The array to merge.
 * @array_c: The temporary array.
 * @l: The left index of the split-array.
 * @m: The mid-point of the split-array.
 * @r: The right index of the split-array.
 */
void top_down_merge(int *array, int *array_c, size_t l, size_t m, size_t r)
{
	size_t a = l, b = m, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + (m), r - m);
	for (c = l; c < r; c++)
	{
		if ((a < m) && ((b >= r) || (array_c[a] <= array_c[b])))
		{
			array[c] = array_c[a++];
		}
		else
		{
			array[c] = array_c[b++];
		}
	}
	printf("[Done]: ");
	print_array(array + l, r - l);
}

/**
 * split_merge - Sorts an array that has been split using the
 * merge sort algorithm.
 * @array: The array that has been split.
 * @array_c: The temporary array.
 * @size: The length of the original array.
 * @l: The left index of the split-array.
 * @r: The right index of the split-array.
 */
void split_merge(int *array, int *array_c, size_t size, size_t l, size_t r)
{
	size_t i, mid;

	if ((r - l) <= 1)
		return;
	mid = (l + r) / 2;
	split_merge(array, array_c, size, l, mid);
	split_merge(array, array_c, size, mid, r);
	for (i = l; i <= r + (r == size ? -1 : 0); i++)
		array_c[i] = array[i];
	top_down_merge(array, array_c, l, mid, r);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *array_c = NULL;

	if (array != NULL)
	{
		array_c = malloc(sizeof(int) * size);
		if (array_c != NULL)
		{
			for (i = 0; i < size; i++)
				array_c[i] = array[i];
			split_merge(array, array_c, size, 0, size);
			free(array_c);
		}
	}
=======
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
}
