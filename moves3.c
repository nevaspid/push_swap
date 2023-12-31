/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:42:31 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:24:35 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	if (stack->len_a == 0 || stack->len_b == 0)
		return ;
	rra(stack, 1);
	rrb(stack, 1);
	write (1, "rrr\n", 4);
}
