#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int	main(void)
{
	int	arr[] = {4, 1, 3, 2};

	for (size_t i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	sort_int_tab(arr, 4);

	for (size_t i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}