/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_int_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:22:16 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 19:43:39 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack *stack)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < stack->len_a)
	{
		while (y < stack->len_a)
		{
			if (stack->a[i] == stack->a[y] && i != y)
				return (1);
			y++;
		}
		i++;
		y = 0;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			return (0);
		}
		i++;
	}
	freeall(stack);
	write (1, "OK\n", 3);
	exit(0);
}
