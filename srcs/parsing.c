#include "the_cake_is_a_lie.h"

int	fill_score(t_cake *c)
{
	int				i;
	unsigned short	lowest;

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
			lowest = c->score[i - 1];
			if (c->score[i - c->line_len] < lowest)
				lowest = c->score[i - c->line_len];
			if (c->score[i - c->line_len - 1] < lowest)
				lowest = c->score[i - c->line_len - 1];
			c->score[i] = lowest + 1;
			c->square_position = i;
			c->square_score = lowest + 1;
		}
	}
}

int	read_map(t_cake *cake)
{
	cake->buffer = malloc(OPTI_BUFFER);
	if (cake->buffer == 0)
		return (-1);
	cake->buffer_len = read(0, cake->buffer, OPTI_BUFFER);
	if (cake->buffer_len == OPTI_BUFFER)
		ft_overbuff(&cake);
	cake->score = malloc(sizeof(unsigned short) * cake->buffer_len);
	fill_score(cake);
}