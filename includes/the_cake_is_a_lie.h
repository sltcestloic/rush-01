#ifndef THE_CAKE_IS_A_LIE_H
# define THE_CAKE_IS_A_LIE_H

# define OPTI_BUFFER 200000005

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_cake
{
	char			*buffer;
	int				line_len;
	int				buffer_len;
	int				square_position;
	unsigned short	square_score;
	unsigned short	*score;
}				t_cake;

void	read_map(t_cake *cake);
void	print_cake(t_cake *cake);

#endif 