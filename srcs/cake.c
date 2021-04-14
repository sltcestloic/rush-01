#include "the_cake_is_a_lie.h"

static inline void	print_cake(t_cake *cake)
{
	register unsigned short	score;
	register int				i;

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

static inline void	fill_score(t_cake *c, int i)
{
	register unsigned short *score_a;
	register unsigned short *score_b;
	register unsigned short *swap;

	score_a = malloc(c->line_len);
	score_b = malloc(c->line_len);
	register int j = -1;
	while (++j < c->buffer_len)
	{
		i++;
		if (c->line_len == 0 && c->buffer[i] == '\n')
			c->line_len = i + 1;
		else if (c->line_len == 0 || (i % c->line_len) == 0)
			score_b[i] = 1;
		else if (c->buffer[i] == '\n')
		{
			swap = score_a;
			score_a = score_b;
			score_b = swap;
			i = -1;
		}
		else if (c->buffer[j - 1] != c->buffer[j] || c->buffer[j - c->line_len]
			!= c->buffer[j] || c->buffer[j - 1 - c->line_len] != c->buffer[j])
			score_b[i] = 1;
		else
		{
			score_b[i] = score_b[i - 1];
			if (score_a[i] < score_b[i])
				score_b[i] = score_a[i];
			if (score_a[i - 1] < score_b[i])
				score_b[i] = score_a[i - 1];
			if (++score_b[i] > c->square_score)
			{
				c->square_position = j;
				c->square_score = score_b[i];
			}
		}
	}
	free(score_a);
	free(score_b);
}
#include <time.h>
#include <stdio.h>
int	main(void)
{
	clock_t begin = clock();
	t_cake	cake;
	register int		i;

	cake.line_len = 0;
	cake.square_score = 0;
	cake.buffer_len = 0;
	i = 1;
	cake.buffer = malloc(OPTI_BUFFER);
	while (i)
	{
		i = read(0, &cake.buffer[cake.buffer_len], 4096);
		cake.buffer_len += i;
	}
	cake.buffer[cake.buffer_len] = 0;
	i = 0;
	while (cake.buffer[i] != '.')
		i++;
	cake.buffer_len -= i + 2;
	cake.buffer = &cake.buffer[i + 2];
	fill_score(&cake, -1);
	print_cake(&cake);
	free(cake.buffer - (2 + i));
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time);
	return (0);
}
