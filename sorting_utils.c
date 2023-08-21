/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:02:25 by gloms             #+#    #+#             */
/*   Updated: 2023/08/20 21:23:02 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *s)
{
	int	i;
	int	index_of_the_smallest;

	i = -1;
	index_of_the_smallest = 0;
	while (++i < s->len_a)
		if (s->a[i] < s->a[index_of_the_smallest])
			index_of_the_smallest = i;
	return (index_of_the_smallest);
}

void	small_to_top(t_stack *s)
{
	int	i;

	i = find_smallest(s);
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

int	find_biggest(t_stack *s)
{
	int	i;
	int	index_of_biggest;

	i = 0;
	index_of_biggest = 0;
	while (++i < s->len_a)
	{
		if (s->a[i] > s->a[index_of_biggest])
			index_of_biggest = i;
	}
	return (index_of_biggest);
}

int	median(t_stack *s)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	s->sortedtab = malloc(sizeof(int) * s->len_a);
	while (++i < s->len_a)
		s->sortedtab[i] = s->a[i];
	i = -1;
	while (++i < s->len_a)
	{
		j = i + 1;
		while (j < s->len_a)
		{
			if (s->sortedtab[i] > s->sortedtab[j])
			{
				tmp = s->sortedtab[i];
				s->sortedtab[i] = s->sortedtab[j];
				s->sortedtab[j] = tmp;
			}
			j++;
		}
	}
	return (s->sortedtab[s->len_a / 2]);
}

int	bestplace(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (++i < s->len_a)
	{
		if (s->a[i] > value && s->a[i - 1] < value)
			return (i);
	}
	return (0);
}
