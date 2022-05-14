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

	len = get_digits_len(time);
	if (time == 1)
	{
		s = (char *)malloc(len + ft_strlen(" ") +
								 ft_strlen(time_unit) +
								 ft_strlen(" ago.") + 1);
		if (!s)
			return (0);
		n = mini_itoa(time);
		ft_strcat(s, n);
		free(n);
		ft_strcat(s, " ");
		ft_strcat(s, time_unit);
		ft_strcat(s, " ago.");
	}
	else
	{
		s = (char *)malloc(len + ft_strlen(" ") +
								 ft_strlen(time_unit) +
								 ft_strlen("s ago.") + 1);
		if (!s)
			return (0);
		n = mini_itoa(time);
		ft_strcat(s, n);
		free(n);
		ft_strcat(s, " ");
		ft_strcat(s, time_unit);
		ft_strcat(s, "s ago.");
	}
	return (s);
}

char	*ft_strcat(char *dst, char *src)
{
	char	*bkp;

	bkp = dst;
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (bkp);
}

char	*mini_itoa(unsigned int n)
{
	char	*s;
	int		size;

	size = get_digits_len(n) + 1;
	s = malloc(size + 1);
	if (!s)
		return (0);
	size--;		// back to the position of the null-character
	s[size] = 0;
	size--;		// back once more to the position of the least significant digit
	while (size >= 0)
	{
		s[size] = (n % 10) + '0';
		n /= 10;
		size--;
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
