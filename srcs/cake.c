#include "the_cake_is_a_lie.h"

void	print_cake(t_cake *cake)
{
	unsigned short	score;
	int				i;

	score = cake->square_score;
	i = cake->square_position;
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

void	fill_score(t_cake *c)
{
	int				i;

	i = -1;
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
			if (c->score[i]++ > c->square_score)
			{
				c->square_position = i;
				c->square_score = c->score[i];
			}
		}
	}
}

void	read_map(t_cake *cake)
{
	int i = 0;
	cake->buffer = malloc(OPTI_BUFFER);
	cake->buffer_len = read(0, cake->buffer, OPTI_BUFFER);
	while(cake->buffer[i] != '.')
		i++;
	cake->buffer_len -= i + 2;
	cake->buffer = &cake->buffer[i + 2];
	cake->score = malloc(sizeof(unsigned short) * cake->buffer_len);
	fill_score(cake);
}

int	main(void)
{
	t_cake	cake;

	cake.line_len = 0;
	read_map(&cake);
	print_cake(&cake);
	return (0);
}
