/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:43:38 by gloms             #+#    #+#             */
/*   Updated: 2023/08/25 09:26:47 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigsort(t_stack *s, t_costs *c)
{
	s->median = median(s);
	step_1(s);
	while (s->len_b)
	{
		init_cost(c);
		define_index(c, s);
		apply_moves(s, c);
	}
	small_to_top(s);
}

void	step_1(t_stack *s)
{
	while (s->len_a > (s->len_a + s->len_b) / 2 + 2)
	{
		if (find_biggest(s) == 0 || find_smallest(s) == 0)
			ra(s, 0);
		else if (s->a[0] < s->median + 1)
			pb(s);
		else
			ra(s, 0);
	}
	while (s->len_a > 2)
	{
		if (find_biggest(s) == 0 || find_smallest(s) == 0)
			ra(s, 0);
		else
			pb(s);
	}
}

void	apply_moves(t_stack *s, t_costs *c)
{
	while (c->ra--)
		ra(s, 0);
	while (c->rb--)
		rb(s, 0);
	while (c->rrb--)
		rrb(s, 0);
	while (c->rra--)
		rra(s, 0);
	while (c->rr--)
		rr(s);
	while (c->rrr--)
		rrr(s);
	pa(s);
}

void	init_cost(t_costs *c)
{
	c->ra_tmp2 = 0;
	c->rb_tmp2 = 0;
	c->rr_tmp2 = 0;
	c->rra_tmp2 = 0;
	c->rrb_tmp2 = 0;
	c->rrr_tmp2 = 0;
	c->total_tmp2 = 2147483647;
	c->ra_tmp = 0;
	c->rb_tmp = 0;
	c->rr_tmp = 0;
	c->rra_tmp = 0;
	c->rrb_tmp = 0;
	c->rrr_tmp = 0;
	c->total_tmp = 2147483647;
	c->ra = 0;
	c->rb = 0;
	c->rr = 0;
	c->rra = 0;
	c->rrb = 0;
	c->rrr = 0;
	c->total = 2147483647;
}

void	define_index(t_costs *c, t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->len_b)
	{
		if (cost_calculation(i, s, c) < c->total)
			newcostless2(c);
	}
}
