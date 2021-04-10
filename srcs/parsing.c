#include "the_cake_is_a_lie.h"

int	read_map()
{
	int size;
	t_cake buff;
	unsigned short *score;

	buff = malloc(OPTI_BUFFER);
	if (buff == 0)
		return (-1);
	size = read(0, buff, OPTI_BUFFER);
	if (size == OPTI_BUFFER)
		ft_overbuff(buff);
	score = malloc(sizeof(unsigned short) * size);

}