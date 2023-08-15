/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:30:59 by gloms             #+#    #+#             */
/*   Updated: 2023/08/15 01:11:30 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_least_cost(t_costs *c)
{
	c->ra_tmp = c->ra_tmp2;
	c->rb_tmp = c->rb_tmp2;
	c->rr_tmp = c->rr_tmp2;
	c->rra_tmp = c->rra_tmp2;
	c->rrb_tmp = c->rrb_tmp2;
	c->rrr_tmp = c->rrr_tmp2;
	c->total_tmp = c->total_tmp2;
	c->ra_tmp2 = 0;
	c->rb_tmp2 = 0;
	c->rr_tmp2 = 0;
	c->rra_tmp2 = 0;
	c->rrb_tmp2 = 0;
	c->rrr_tmp2 = 0;
	c->total_tmp2 = 2147483647;
}

void	individual_cost(int index_a, int index_b, t_stack *s, t_costs *c)
{
	int i;
	int	j;

	if (index_b >= s->len_b / 2)
	{
		i = s->len_b - index_b;
		c->rrb_tmp2;
	}
	else
	{
		i = index_b;
		c->rb_tmp2
	}
	if (index_a >= s->len_a / 2)
		c->rra_tmp2 = s->len_a - index_a;
	else
		c->ra_tmp2 = index_a;
	//il reste a checker les individual costs de ra ou rra et tester la fonction big_to_top /!\
}
