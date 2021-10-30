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
 * sift_down - Moves the largest element in an array to its correct
 * sorted position in a max-heap sub-array.
 * @array: The array to sort.
 * @arr_size: The length of the array.
 * @size: The length of the max heap sub-array.
 * @pos: The position of the largest element in the max heap sub-array.
 */
void sift_down(int *array, int arr_size, int size, int pos)
{
	int j, child;

	j = pos;
	while (j < (size / 2))
	{
		child = (2 * j) + 1;
		if ((child < (size - 1)) && (array[child] < array[child + 1]))
			child++;
		if (array[j] >= array[child])
			return;
		swap_items(array, j, child);
		print_array(array, arr_size);
		j = child;
	}
}

/**
 * build_max_heap - Builds a max heap binary tree with the given array.
 * @array: The array to convert to a max heap binary tree.
 * @size: The length of the array.
 */
void build_max_heap(int *array, int size)
{
	int a;

	for (a = (size / 2) - 1; a >= 0; a--)
	{
		sift_down(array, size, size, a);
=======
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
	}
}

/**
<<<<<<< HEAD
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, n;

	build_max_heap(array, size);
	n = size;
	for (i = 0; i < (int)size; i++)
	{
		swap_items(array, --n, 0);
		if (n != 0)
		{
			print_array(array, size);
			sift_down(array, size, n, 0);
		}
=======
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
	}
}
