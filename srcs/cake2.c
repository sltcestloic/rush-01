#include "the_cake_is_a_lie.h"
#include <stdio.h>
static inline ssize_t	print_cake(register t_cake *cake)
{
	register unsigned short	score;
	register int			i;

	score = cake->square_score;
	i = cake->square_position;
	if (score == 0)
		cake->buffer[0] = '.';
	while (score)
	{
		while (i > cake->square_position - cake->square_score)
		{
			cake->buffer[i] = '.';
			i--;
		}
		i = cake->square_position - cake->line_len - 1;
		cake->square_position = i;
		score--;
	}
	return write(1, cake->buffer, cake->buffer_len);
}

static inline void *memalloc(size_t size)
{
	register char *ptr;

	ptr = (char*)malloc(size);
	while (size--)
		ptr[size] = 0;
	return ((void*)ptr);
}

static inline int compute_cell_score(register t_cake *ck, register size_t i, register size_t j, register char c)
{
	if (j > 0 && i > 0 && ck->buffer[(i - 1) * ck->line_len + j - 1 + i] == c &&
		ck->buffer[(i - 1) * ck->line_len + j + i] == c &&
		ck->buffer[i * ck->line_len + j - 1 + i] == c)
	{
		return (ck->lines[0][j - 1] + 1);
	}
	return 1;
}

static inline void compute_score(register t_cake *c)
{
	register size_t	i;
	register size_t	j;
	register char	current;
	register t_u16 *swap;

	i = 0;
	while (i < c->line_len)
	{
		j = 0;
		while (j < c->line_len)
		{
			current = c->buffer[i * c->line_len + j + i];
			c->lines[1][j] = compute_cell_score(c, i, j, current);
			if (c->lines[1][j] > c->square_score)
			{
				c->square_score = c->lines[1][j];
				c->square_position = i * c->line_len + j + i;
			}
			j++;
		}
		swap = c->lines[0];
		c->lines[0] = c->lines[1];
		c->lines[1] = swap;
		i++;
	}
}

int	main(void)
{
	t_cake				cake;
	register int		i;

	cake = (t_cake){0};
	cake.buffer = malloc(OPTI_BUFFER);
	while (cake.buffer_len == 0 || i)
	{
		i = read(0, &cake.buffer[cake.buffer_len], 4096);
		cake.buffer_len += i;
	}
	i = 0;
	while (cake.buffer[i] != '.')
		i++;
	cake.buffer_len -= i + 2;
	cake.buffer += (i + 2);
	while (cake.buffer[cake.line_len] != '\n')
		cake.line_len++;
	cake.score_data = memalloc(sizeof(t_u16) * cake.line_len * 2);
	cake.lines[0] = cake.score_data;
	cake.lines[1] = cake.score_data + cake.line_len;
	compute_score(&cake);
	print_cake(&cake);
	free(cake.buffer - (2 + i));
	free(cake.score_data);
	return (0);
}
