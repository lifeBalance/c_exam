/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 04:41:31 by kibotrel          #+#    #+#             */
/*   Updated: 2022/05/22 19:40:17 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		check_options(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '-')
			while (av[i][++j])
				if (av[i][j] < 'a' || av[i][j] > 'z')
					return (0);
	}
	return (1);
}

int		check_usage(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '-')
			while (av[i][++j])
				if (av[i][j] == 'h')
					return (1);
	}
	return (0);
}

int		check_letter(char **av, char c)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '-')
			while (av[i][++j])
				if (av[i][j] == c)
					return (1);
	}
	return (0);
}

void	print_options(char **av)
{
	char	c;
	int		way;

	c = '{';
	write(1, "000000", 6);
	while (--c >= 'a')
	{
		way = check_letter(av, c);
		if (way && (c == 'y' || c == 'q' || c == 'i'))
			write(1, "1 ", 2);
		else if (!way && (c == 'y' || c == 'q' || c == 'i'))
			write(1, "0 ", 2);
		else if (way)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!check_options(av))
			return (0 * write(1, "Invalid Option\n", 15));
		if (check_usage(av))
			return (0 * write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
		print_options(av);
	}
	else
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}
