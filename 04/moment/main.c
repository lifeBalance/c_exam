#include <stdio.h>
#include <stdlib.h>

char	*moment(unsigned int duration);

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", moment(atoi(argv[1])));
	return (0);
}