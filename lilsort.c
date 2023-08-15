/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lilsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:51:38 by gloms             #+#    #+#             */
/*   Updated: 2023/08/11 19:20:18 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

void	sort3(t_stack *s)
{
	if (s->a[2] > s->a[0] && s->a[0] > s->a[1])
		sa(s);
	else if (s->a[0] > s->a[2] && s->a[1] > s->a[0])
		rra(s, 0);
	else if (s->a[1] > s->a[0] && s->a[1] > s->a[2])
	{
		rra(s, 0);
		sa(s);
	}
	else if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		sa(s);
		rra(s, 0);
	}
	else if (s->a[0] > s->a[1] && s->a[2] > s->a[1])
		ra(s, 0);
}

void	sort5(t_stack *s)
{
	small_to_top(s);
	pb(s);
	small_to_top(s);
	pb(s);
	sort3(s);
	pa(s);
	pa(s);
}

void	lilsort(t_stack *s, int sort)
{
	if (sort == 2)
		sort2(s);
	if (sort == 3)
		sort3(s);
	if (sort == 5)
		sort5(s);
}
