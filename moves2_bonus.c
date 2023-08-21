/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:50:58 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:23:54 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_bonus(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->len_a == 0)
		return ;
	i = -1;
	last = stack->a[0];
	while (++i < stack->len_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->len_a - 1] = last;
}

void	rb_bonus(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->len_b == 0)
		return ;
	i = -1;
	last = stack->b[0];
	while (++i < stack->len_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[stack->len_b - 1] = last;
}

void	rr_bonus(t_stack *stack)
{
	if (stack->len_a == 0 || stack->len_b == 0)
		return ;
	ra_bonus(stack);
	rb_bonus(stack);
}

void	rra_bonus(t_stack *stack)
{
	int	i;
	int	first;

	if (stack->len_a == 0)
		return ;
	i = stack->len_a;
	first = stack->a[stack->len_a - 1];
	while (--i >= 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = first;
}

void	rrb_bonus(t_stack *stack)
{
	int	i;
	int	first;

	if (stack->len_b == 0)
		return ;
	i = stack->len_b;
	first = stack->b[stack->len_b - 1];
	while (--i >= 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = first;
}
