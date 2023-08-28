/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:01:52 by gloms             #+#    #+#             */
/*   Updated: 2023/08/28 22:16:11 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freetab(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_costs	costs;

	if (ac == 1)
		return (write(1, "Error\n", 6), EXIT_FAILURE);
	stack = malloc(sizeof(t_stack));
	stack->len_b = 0;
	if (ac == 1 || parser(av, stack) == 1)
	{
		freeall(stack);
		return (write(1, "Error\n", 6), EXIT_FAILURE);
	}
	if (ac == 3 || ac == 4 || ac == 6)
		lilsort(stack, ac - 1);
	else
		bigsort(stack, &costs);
	freeall(stack);
	return (0);
}
