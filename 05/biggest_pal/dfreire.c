/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfreire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:00:07 by dfreire           #+#    #+#             */
/*   Updated: 2022/05/22 16:54:15 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int len;
	
	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}
void biggest_pal(char *s)
{
	int i;
	int len;
	int low;
	int high;
	int max_len;
	int start;

	len = ft_strlen(s);
	if (len == 1)
	{
		write(1, s, 1);
		return ;
	}
	i = 1;
	max_len = 1;
	while (i < len)
	{ 
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 > max_len)
			{
				start = low;
				max_len = high - low + 1;
			}
			--low;
			++high;
		}
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 > max_len)
			{
				start = low;
				max_len = high - low + 1;
			}
			--low;
			++high;
		}
		i++;
	}
	write(1, s + start, max_len);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
