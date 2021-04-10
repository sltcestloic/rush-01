#include "the_cake_is_a_lie.h"

int	read_map()
{
	int size;
	char *buff;

	buff = malloc(1000000);
	if (buff == 0)
		return (-1);
	size = read(0, buff, 1000000);
	if (size == 1000000)
		ft_realloc(buff);
	
}