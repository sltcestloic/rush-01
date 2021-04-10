/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:05:41 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/10 14:31:55 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/the_cake_is_a_lie.h"
#include <string.h>

void	print_square(t_cake *cake)
{
	int	score;
	int	i;

	score = cake->square_score;
	i = cake->square_position;
	while (cake->square_score)
	{
		while (i > cake->square_position - score)
		{
			cake->buffer[i] = '.';
			i--;
		}
		i = cake->square_position - cake->line_len;
		cake->square_position = i;
		cake->square_score--;
	}
	printf("%s\n", cake->buffer);
}

// int main()
// {
// 	t_cake *cake = malloc(sizeof(t_cake *)); 

// 	cake->buffer = malloc(sizeof(char) * ((6 * 7) + 1));
// 	strcpy(cake->buffer,"0000000\n0111100\n0122200\n0123300\n0123400\n0000000");
// 	cake->line_len = 8;
// 	cake->square_position = 36;
// 	cake->square_score = 4;
// 	printf("%s\n", cake->buffer);
// 	print_square(cake);
// }
