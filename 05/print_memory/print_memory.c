#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_byte_char(unsigned char b)
{
	char	ch;

	ch = (char)b;
	if (b >= ' ' && b <= '~')
		write(1, &ch, 1);
	else
		write(1, ".", 1);
}

void	print_byte_hex(unsigned char ch)
{
	write(1, &"0123456789abcdef"[ch / 16], 1);
	write(1, &"0123456789abcdef"[ch % 16], 1);
}

int		print_line(unsigned char *arr, int i, int size)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			print_byte_hex(arr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2 != 0)
			write(1, " ", 1);
		j++;
	}
	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			print_byte_char(arr[i + j]);
		else
			break;
		j++;
	}
	write(1, "\n", 1);
	return (16);
}

void	print_memory(const void *addr, size_t size)
{
	int				i;
	unsigned char	*arr;

	arr = (unsigned char*)addr;
	i = 0;
	while (i < (int)size)
		i += print_line(arr, i, size);
}
