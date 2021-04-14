#ifndef THE_CAKE_IS_A_LIE_H
# define THE_CAKE_IS_A_LIE_H

# define OPTI_BUFFER 1073774594

# include <unistd.h>
# include <stdlib.h>

typedef struct s_cake
{
	char			*buffer;
	int				line_len;
	int				buffer_len;
	int				square_position;
	unsigned short	square_score;
	unsigned short	*score_a;
	unsigned short	*score_b;
	unsigned short	*swap;
}				t_cake;

#endif 