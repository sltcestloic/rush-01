/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:05:41 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/10 14:44:58 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/the_cake_is_a_lie.h"
#include <string.h>

void	print_square(t_cake *cake)
{
	unsigned short	score;
	int				i;

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
	write(1, cake->buffer, cake->buffer_len);
}
