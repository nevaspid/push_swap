/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:11:49 by gloms             #+#    #+#             */
/*   Updated: 2023/08/13 18:07:43 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser(char **av, t_stack *stack)
{
	int	i;
	int	atoi_error;

	i = -1;
	atoi_error = 0;
	if (check_space(av) == 0 && !av[2])
		av = ft_split(av[1], ' ');
	stack->a = malloc(sizeof(int) * arg_count(av, &atoi_error, stack));
	while (av[++i + 1])
	{
		stack->a[i] = ft_atoi(av[i + 1], &atoi_error);
		if (atoi_error == 1)
			return (1);
	}
	if (check_in_int(stack) == 1)
		return (1);
	return (0);
}

int	check_space(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	arg_count(char **av, int *atoi_error, t_stack *stack)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[0])
			*atoi_error = 1;
		i++;
	}
	stack->len_a = i - 1;
	return (i);
}

int	check_in_int(t_stack *stack)
{
	if (check_doubles(stack) == 1)
		return (1);
	if (check_sorted(stack) == 0)
		return (0);
	return (0);
}
