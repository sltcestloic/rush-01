#include "the_cake_is_a_lie.h"

static inline void	print_cake(t_cake *cake)
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
		i = cake->square_position - cake->line_len;
		cake->square_position = i;
		score--;
	}
	write(1, cake->buffer, cake->buffer_len);
}

static inline void	swap(t_cake *cake, register int *i)
{
	cake->swap = cake->score_a;
	cake->score_a = cake->score_b;
	cake->score_b = cake->swap;
	*i = -1;
}

static inline void	fill_score(t_cake *c, int i, register int j)
{
	while (++j < c->buffer_len && ++i > -1)
	{
		if (c->line_len == 0 && c->buffer[j] == '\n')
			c->line_len = i + 1;
		else if (i == 0)
			c->score_b[i] = 1;
		if (c->buffer[i] == '\n')
			swap(c, &i);
		else if (c->buffer[j - 1] != c->buffer[j] || c->buffer[j - c->line_len]
			!= c->buffer[j] || c->buffer[j - 1 - c->line_len] != c->buffer[j])
			c->score_b[i] = 1;
		else
		{
			c->score_b[i] = c->score_b[i - 1];
			if (c->score_a[i] < c->score_b[i])
				c->score_b[i] = c->score_a[i];
			if (c->score_a[i - 1] < c->score_b[i])
				c->score_b[i] = c->score_a[i - 1];
			if (++c->score_b[i] > c->square_score)
			{
				c->square_position = j;
				c->square_score = c->score_b[i];
			}
		}
	}
}

#include <stdio.h>
#include <time.h>
int	main(void)
{
	clock_t start = clock();
	t_cake			cake;
	register int	i;

	cake.line_len = 0;
	cake.square_score = 0;
	cake.buffer_len = 0;
	cake.score_a = malloc(sizeof(unsigned short) * __SHRT_MAX__);
	cake.score_b = malloc(sizeof(unsigned short) * __SHRT_MAX__);
	cake.buffer = malloc(OPTI_BUFFER);
	while (cake.buffer_len == 0 || i)
	{
		i = read(0, &cake.buffer[cake.buffer_len], 60000);
		cake.buffer_len += i;
	}
	i = 0;
	while (cake.buffer[i] != '.')
		i++;
	cake.buffer_len -= i + 2;
	cake.buffer = &cake.buffer[i + 2];
	fill_score(&cake, -1, -1);
	print_cake(&cake);
	free(cake.buffer - (2 + i));
	free(cake.score_a);
	free(cake.score_b);
	clock_t end = clock();
	printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
