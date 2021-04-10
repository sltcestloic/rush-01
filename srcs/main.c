#include "the_cake_is_a_lie.h"

int	main(void)
{
	t_cake	cake;

	cake.line_len = 0;
	read_map(&cake);
	print_cake(&cake);
	return (0);
}
