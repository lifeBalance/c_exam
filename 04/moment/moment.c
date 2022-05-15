#include <stdlib.h>

#define	SEC_PER_MIN		60
#define	SEC_PER_HOUR	3600
#define	SEC_PER_DAY		86400
#define	SEC_PER_MONTH	2592000

char	*build_moments(unsigned int time, char *time_unit);
int		get_digits_len(unsigned int n);
char	*ft_strcat(char *dst, char *src);
char	*mini_itoa(unsigned int n);
int		ft_strlen(char *s);

char	*moment(unsigned int duration)
{
	char	*s;

	if (duration >= SEC_PER_MONTH)
		s = build_moments(duration / SEC_PER_MONTH, "month");
	else if (duration >= SEC_PER_DAY && duration < SEC_PER_MONTH)
		s = build_moments(duration / SEC_PER_DAY, "day");
	else if (duration >= SEC_PER_HOUR && duration < SEC_PER_DAY)
		s = build_moments(duration / SEC_PER_HOUR, "hour");
	else if (duration >= SEC_PER_MIN && duration < SEC_PER_HOUR)
		s = build_moments(duration / SEC_PER_MIN, "minute");
	else
		s = build_moments(duration, "second");
	return (s);
}

char	*build_moments(unsigned int time, char *time_unit)
{
	char	*s;
	char	*n;
	int		len;

	len =	get_digits_len(time) +
			ft_strlen(" ") +
			ft_strlen(time_unit) +
			ft_strlen(" ago.");
	if (time != 1)
		len += ft_strlen("s");
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	n = mini_itoa(time);
	ft_strcat(s, n);
	free(n);
	ft_strcat(s, " ");
	ft_strcat(s, time_unit);
	if (time != 1)
		ft_strcat(s, "s");
	ft_strcat(s, " ago.");
	return (s);
}

char	*ft_strcat(char *dst, char *src)
{
	char	*tmp;

	tmp = dst;
	while (*tmp)
		tmp++;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (dst);
}

char	*mini_itoa(unsigned int n)
{
	char	*s;
	int		len;

	len = get_digits_len(n);
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = 0;	// len is at the position of the null-character
	len--;		// move to the least significant digit
	while (len >= 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (s);
}

int		get_digits_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
