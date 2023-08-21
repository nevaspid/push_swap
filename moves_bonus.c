/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:51:24 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:22:26 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_bonus(t_stack *stack)
{
	int	to_swap;

	to_swap = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = to_swap;
	return ;
}

void	sb_bonus(t_stack *stack)
{
	int	to_swap;

	to_swap = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = to_swap;
	return ;
}

void	ss_bonus(t_stack *stack)
{
	int	to_swap;
	int	to_swap_b;

	to_swap = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = to_swap;
	to_swap_b = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = to_swap_b;
	return ;
}

void	pa_bonus(t_stack *stack)
{
	int	*b_p;
	int	*a_p;
	int	i;
	int	y;

	y = 0;
	i = 0;
	if (stack->len_b == 0)
		return ;
	stack->len_b -= 1;
	stack->len_a += 1;
	b_p = malloc(sizeof(int) * stack->len_b);
	a_p = malloc(sizeof(int) * stack->len_a);
	a_p[0] = stack->b[0];
	while (++i < stack->len_a)
		a_p[i] = stack->a[i - 1];
	while (++y < stack->len_b + 1)
		b_p[y - 1] = stack->b[y];
	free(stack->a);
	free(stack->b);
	stack->a = a_p;
	stack->b = b_p;
}

void	pb_bonus(t_stack *stack)
{
	int	*b_p;
	int	*a_p;
	int	i;
	int	y;

	y = 0;
	i = 0;
	if (stack->len_a == 0)
		return ;
	stack->len_a -= 1;
	stack->len_b += 1;
	a_p = malloc(sizeof(int) * stack->len_a);
	b_p = malloc(sizeof(int) * stack->len_b);
	b_p[0] = stack->a[0];
	while (++i < stack->len_b)
		b_p[i] = stack->b[i - 1];
	while (++y < stack->len_a + 1)
		a_p[y - 1] = stack->a[y];
	free(stack->a);
	free(stack->b);
	stack->a = a_p;
	stack->b = b_p;
}
