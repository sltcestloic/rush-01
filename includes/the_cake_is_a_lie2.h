#ifndef THE_CAKE_IS_A_LIE_H
# define THE_CAKE_IS_A_LIE_H

# define OPTI_BUFFER 1073774594

# include <unistd.h>
# include <stdlib.h>

typedef unsigned short	t_u16;

typedef struct s_score	t_score;

struct s_score
{
	t_u16			score;
	t_u16			_char;
};

typedef struct s_cake
{
	char			*buffer;
	size_t			line_len;
	int				buffer_len;
	int				square_position;
	unsigned short	square_score;

	t_score			*lines[2];
	t_score			*score_data;
}				t_cake;

#endif 
