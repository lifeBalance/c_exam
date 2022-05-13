#include <unistd.h>

#define	ROW 0
#define	COL 1

int		checkmate(char **board, int size);
void	find_king(char **board, int size, int king[2]);
int		check_pawn(int king[2], int pawn[2]);
int		check_rook(char **board, int king[2], int rook[2]);
int		check_bishop(char **board, int king[2], int bishop[2]);
int		blocked(char **board, int r, int c);
int		ft_strlen(char *s);

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (checkmate(argv + 1, argc - 1))
			write(1, "Success", ft_strlen("Success"));
		else
			write(1, "Fail", ft_strlen("Fail"));
	}
	write(1, "\n", 1);
	return (0);
}

int		checkmate(char **board, int size)
{
	int	r;
	int	c;
	int	coord[2];
	int	king[2] = {0};

	find_king(board, size, king);
	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			coord[ROW] = r;
			coord[COL] = c;
			if (board[r][c] == 'P' && check_pawn(king, coord))
				return (1);
			else if (board[r][c] == 'R' && check_rook(board, king, coord))
				return (1);
			else if (board[r][c] == 'B' && check_bishop(board, king, coord))
				return (1);
			else if (board[r][c] == 'Q' &&
				(check_rook(board, king, coord) ||
				check_bishop(board, king, coord)))
				return (1);
			c++;
		}
		r++;
	}
	return(0);
}

int	check_bishop(char **board, int king[2], int bishop[2])
{
	int	i = 1;

	if (king[ROW] + king[COL] == bishop[ROW] + bishop[COL]) // ascending
	{
		while ( bishop[ROW] - i < king[ROW] &&
				bishop[COL] + i < king[COL])
		{
			if (blocked(board, bishop[ROW] - i, bishop[COL] + i))
				return (0);
			i++;
		}
		while ( bishop[ROW] + i < king[ROW] &&
				bishop[COL] - i < king[COL])
		{
			if (blocked(board, bishop[ROW] + i, bishop[COL] - i))
				return (0);
			i++;
		}
		return (1);
	}
	else if (king[ROW] - king[COL] == bishop[ROW] - bishop[COL]) // descending
	{
		while ( bishop[ROW] - i > king[ROW] &&
				bishop[COL] - i > king[COL])
		{
			if (blocked(board, bishop[ROW] - i, bishop[COL] - i))
				return (0);
			i++;
		}
		while ( bishop[ROW] + i < king[ROW] &&
				bishop[COL] + i < king[COL])
		{
			if (blocked(board, bishop[ROW] + i, bishop[COL] + i))
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	check_rook(char **board, int king[2], int rook[2])
{
	int	i;
	int	r;
	int	c;

	i = 1;
	if (king[ROW] == rook[ROW])
	{
		r = king[ROW];
		c = rook[COL];
		while (c + i < king[COL])
		{
			if (blocked(board, r, c + i))
				return (0);
			i++;
		}
		while (c - i > king[COL])
		{
			if (blocked(board, r, c - i))
				return (0);
			i++;
		}
		return (1);
	}
	else if (king[COL] == rook[COL])
	{
		r = rook[ROW];
		c = king[COL];
		while (r + i < king[ROW])
		{
			if (blocked(board, r + i, c))
				return (0);
			i++;
		}
		while (r - i > king[ROW])
		{
			if (blocked(board, r - i, c))
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	blocked(char **board, int r, int c)
{
	return (board[r][c] == 'P' ||
			board[r][c] == 'R' ||
			board[r][c] == 'B' ||
			board[r][c] == 'Q');
}

int	check_pawn(int king[2], int pawn[2])
{
	if (king[ROW] == pawn[ROW] - 1)
		return (king[COL] == pawn[COL] + 1 || king[COL] == pawn[COL] - 1 );
	return (0);
}

void find_king(char **board, int size, int king[2])
{
	int	r;
	int	c;

	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			if (board[r][c] == 'K')
			{
				king[ROW] = r;
				king[COL] = c;
				break;
			}
			c++;
		}
		r++;
	}
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}