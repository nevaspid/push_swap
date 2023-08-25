/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:47:56 by gloms             #+#    #+#             */
/*   Updated: 2023/08/25 10:40:23 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_sign(char *str, int i)
{
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit2(str[i + 1]))
		return (1);
	else
		return (0);
}

int	ft_isdigit(char *str, int i)
{
	if (i == 0 && str[i] == '0' && ft_isdigit2(str[i + 1]))
		return (0);
	if (ft_isdigit2(str[i]) || ft_sign(str, i))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str, int *atoi_error)
{
	int			i;
	int			negamorph;
	long int	number;

	number = 0;
	negamorph = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str, i) || str[i] == '\0')
			return (*atoi_error = 1);
		if (ft_isdigit(str, i) && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (*atoi_error = 1);
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				negamorph = -1;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			number *= 10;
			number += str[i++] - 48;
		}
		if (number > 2147483647 || number < -2147483648)
			return (*atoi_error = 1);
	}
	return (number * negamorph);
}

void	freeall(t_stack *stack)
{
	if (stack)
	{
		if (stack->len_a)
			free(stack->a);
		if (stack->len_b)
			free(stack->b);
		free(stack);
	}
}
