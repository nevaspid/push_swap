/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:30:59 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:19:42 by gloms            ###   ########.fr       */
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
	if (index_b >= s->len_b / 2)
		c->rrb_tmp2 = s->len_b - index_b;
	else
		c->rb_tmp2 = index_b;
	if (index_a >= s->len_a / 2)
		c->rra_tmp2 = s->len_a - index_a;
	else
		c->ra_tmp2 = index_a;
	while (c->ra_tmp2 && c->rb_tmp2)
	{
		c->ra_tmp2--;
		c->rb_tmp2--;
		c->rr_tmp2++;
	}
	while (c->rra_tmp2 && c->rrb_tmp2)
	{
		c->rra_tmp2--;
		c->rrb_tmp2--;
		c->rrr_tmp2++;
	}
	c->total_tmp2 = c->rrb_tmp2 + c->rb_tmp2 + c->rra_tmp2 + c->ra_tmp2
		+ c->rr_tmp2 + c->rrr_tmp2;
}

void	up_cost(int index_a, int index_b, t_costs *c)
{
	c->ra_tmp2 = index_a;
	c->rb_tmp2 = index_b;
	c->rr_tmp2 = 0;
	c->rra_tmp2 = 0;
	c->rrb_tmp2 = 0;
	c->rrr_tmp2 = 0;
	while (c->ra_tmp2 && c->rb_tmp2)
	{
		c->ra_tmp2--;
		c->rb_tmp2--;
		c->rr_tmp2++;
	}
	c->total_tmp2 = c->ra_tmp2 + c->rb_tmp2 + c->rr_tmp2;
}

void	down_cost(int index_a, int index_b, t_stack *s, t_costs *c)
{
	c->rra_tmp2 = s->len_a - index_a;
	c->rrb_tmp2 = s->len_b - index_b;
	c->ra_tmp2 = 0;
	c->rb_tmp2 = 0;
	c->rr_tmp2 = 0;
	c->rrr_tmp2 = 0;
	while (c->rra_tmp2 && c->rrb_tmp2)
	{
		c->rra_tmp2--;
		c->rrb_tmp2--;
		c->rrr_tmp2++;
	}
	c->total_tmp2 = c->rra_tmp2 + c->rrb_tmp2 + c->rrr_tmp2;
}

int	cost_calculation(int index_b, t_stack *s, t_costs *c)
{
	individual_cost(bestplace(s, s->b[index_b]), index_b, s, c);
	set_least_cost(c);
	up_cost(bestplace(s, s->b[index_b]), index_b, c);
	if (c->total_tmp2 < c->total_tmp)
		set_least_cost(c);
	down_cost(bestplace(s, s->b[index_b]), index_b, s, c);
	if (c->total_tmp2 < c->total_tmp)
		set_least_cost(c);
	return (c->total_tmp);
}
