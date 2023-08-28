/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:51:24 by gloms             #+#    #+#             */
/*   Updated: 2023/08/28 22:13:33 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	to_swap;

	to_swap = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = to_swap;
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_stack *stack)
{
	int	to_swap;

	to_swap = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = to_swap;
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack *stack)
{
	int	to_swap;
	int	to_swap_b;

	to_swap = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = to_swap;
	to_swap_b = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = to_swap_b;
	write(1, "ss\n", 3);
	return ;
}

void	pa(t_stack *stack)
{
	int	*b_p;
	int	*a_p;
	int	i;
	int	y;

	y = -1;
	i = -1;
	if (!stack->len_b)
		return ;
	b_p = malloc(sizeof(int) * (stack->len_b - 1));
	a_p = malloc(sizeof(int) * (stack->len_a + 1));
	a_p[0] = stack->b[0];
	while (++i < stack->len_a)
		a_p[i + 1] = stack->a[i];
	while (++y < stack->len_b - 1)
		b_p[y] = stack->b[y + 1];
	free(stack->a);
	free(stack->b);
	stack->a = a_p;
	stack->b = b_p;
	stack->len_b -= 1;
	stack->len_a += 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	int	*b_p;
	int	*a_p;
	int	i;
	int	y;

	y = -1;
	i = -1;
	if (!stack->len_a)
		return ;
	a_p = malloc(sizeof(int) * (stack->len_a - 1));
	b_p = malloc(sizeof(int) * (stack->len_b + 1));
	b_p[0] = stack->a[0];
	while (++i < stack->len_b)
		b_p[i + 1] = stack->b[i];
	while (++y < stack->len_a - 1)
		a_p[y] = stack->a[y + 1];
	free(stack->a);
	if (stack->len_b)
		free(stack->b);
	stack->a = a_p;
	stack->b = b_p;
	stack->len_a -= 1;
	stack->len_b += 1;
	write(1, "pb\n", 3);
}
