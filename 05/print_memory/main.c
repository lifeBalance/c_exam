#include <unistd.h>
#include <stdio.h>

void	print_memory(const void *addr, size_t size);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	// printf("size: %zu (%zu)\n", sizeof(tab), sizeof(tab) / sizeof(int));
	print_memory(tab, sizeof(tab));
	return (0);
}