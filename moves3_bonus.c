/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:42:31 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:23:34 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_bonus(t_stack *stack)
{
	if (stack->len_a == 0 || stack->len_b == 0)
		return ;
	rra_bonus(stack);
	rrb_bonus(stack);
}
