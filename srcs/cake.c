#include "the_cake_is_a_lie.h"

void	print_cake(t_cake *cake)
{
	unsigned short	score;
	int				i;

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
#include <stdio.h>
void	fill_score(t_cake *c, int i)
{
	while (++i < c->buffer_len)
	{
		if (c->line_len == 0 && c->buffer[i] == '\n')
			c->line_len = i + 1;
		if (c->line_len == 0 || (i % c->line_len) == 0)
			c->score[i] = 1;
		else if (c->buffer[i - 1] != c->buffer[i] || c->buffer[i - c->line_len]
			!= c->buffer[i] || c->buffer[i - 1 - c->line_len] != c->buffer[i])
			c->score[i] = 1;
		else
		{
			c->score[i] = c->score[i - 1];
			if (c->score[i - c->line_len] < c->score[i])
				c->score[i] = c->score[i - c->line_len];
			if (c->score[i - c->line_len - 1] < c->score[i])
				c->score[i] = c->score[i - c->line_len - 1];
			if (++c->score[i] > c->square_score)
			{
				c->square_position = i;
				c->square_score = c->score[i];
			}
		}
	}
}

int	main(void)
{
	t_cake	cake;
	int		i;

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
	cake.score = malloc(sizeof(unsigned short) * cake.buffer_len);
	fill_score(&cake, -1);
	print_cake(&cake);
	free(cake.buffer - (2 + i));
	free(cake.score);
	return (0);
}
