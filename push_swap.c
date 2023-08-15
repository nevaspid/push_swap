/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:01:52 by gloms             #+#    #+#             */
/*   Updated: 2023/08/14 21:21:46 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *stack)
{
	int i;

	i = -1;

	while (++i < stack->len_a)
		printf("a[%d] = %d\n", i, stack->a[i]);
	i = -1;
	printf("============\n");
	while (++i < stack->len_b)
		printf("b[%d] = %d\n", i, stack->b[i]);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	if (ac == 2)
		return (0);
	stack = malloc(sizeof(t_stack));
	stack->len_b = 0;
	if (ac == 1 || parser(av, stack) == 1)
		return (write(1, "Error\n", 6), EXIT_FAILURE);
	// if (ac == 3 || ac == 4 || ac == 6)
	// 	lilsort(stack, ac - 1);
	// else
	// 	bigsort(stack);
	big_to_top(stack);
	print_stacks(stack);
}
