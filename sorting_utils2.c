/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:08:36 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:23:08 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_to_top(t_stack *s)
{
	int	i;

	i = find_biggest(s);
	if (i >= s->len_a / 2)
	{
		i = s->len_a - i;
		while (--i >= 0)
			rra(s, 0);
	}
	else
	{
		i++;
		while (--i != 0)
			ra(s, 0);
	}
}

void	newcostless2(t_costs *c)
{
	c->ra = c->ra_tmp;
	c->rb = c->rb_tmp;
	c->rr = c->rr_tmp;
	c->rra = c->rra_tmp;
	c->rrb = c->rrb_tmp;
	c->rrr = c->rrr_tmp;
	c->total = c->total_tmp;
	c->ra_tmp = 0;
	c->rb_tmp = 0;
	c->rr_tmp = 0;
	c->rra_tmp = 0;
	c->rrb_tmp = 0;
	c->rrr_tmp = 0;
	c->total_tmp = 2147483647;
}
