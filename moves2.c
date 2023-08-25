/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:50:58 by gloms             #+#    #+#             */
/*   Updated: 2023/08/25 11:23:38 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int rr)
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
	if (rr == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int rr)
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
	if (rr == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	if (stack->len_a == 0 || stack->len_b == 0)
		return ;
	ra(stack, 1);
	rb(stack, 1);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack, int rrr)
{
	int	i;
	int	first;

	if (stack->len_a == 0)
		return ;
	i = stack->len_a;
	first = stack->a[stack->len_a - 1];
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = first;
	if (rrr == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int rrr)
{
	int	i;
	int	first;

	if (stack->len_b == 0)
		return ;
	i = stack->len_b;
	first = stack->b[stack->len_b - 1];
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = first;
	if (rrr == 0)
		write(1, "rrb\n", 4);
}
