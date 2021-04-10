#include "the_cake_is_a_lie.h"

int	main(void)
{
	t_cake	cake;

	cake.line_len = 0;
	read_map(&cake);
	print_square(&cake);
	//printf("Sqr_pos = %d\nSqr_score = %d\nLine_len = %d\nBuff_len = %d\n", cake.square_position, cake.square_score, cake.line_len, cake.buffer_len);
	return (0);
}
