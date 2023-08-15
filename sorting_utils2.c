/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:08:36 by gloms             #+#    #+#             */
/*   Updated: 2023/08/14 21:15:47 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void big_to_top(t_stack *s)
{
	int	i;

	i = find_biggest(s);

	if (i >= s->len_a / 2)
	{
		i = s->len_a - i;
		while (--i >= 0)
			rra(s, 0);
	}
	else
	{
		i++;
		while (--i != 0)
			ra(s, 0);
	}
}
