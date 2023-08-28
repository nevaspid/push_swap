/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:17:55 by gloms             #+#    #+#             */
/*   Updated: 2023/08/28 23:51:52 by gloms            ###   ########.fr       */
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

void	reader(t_stack *s)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return ;
		move(s, line);
		free(line);
	}
}

void	move(t_stack *s, char *line)
{
	if (ft_strncmp(line, "ra\n", 2147483647) != 0)
		ra_bonus(s);
	else if (ft_strncmp(line, "rb\n", 2147483647) != 0)
		rb_bonus(s);
	else if (ft_strncmp(line, "rra\n", 2147483647) != 0)
		rra_bonus(s);
	else if (ft_strncmp(line, "rrb\n", 2147483647) != 0)
		rrb_bonus(s);
	else if (ft_strncmp(line, "rr\n", 2147483647) != 0)
		rr_bonus(s);
	else if (ft_strncmp(line, "rrr\n", 2147483647) != 0)
		rrr_bonus(s);
	else if (ft_strncmp(line, "pa\n", 2147483647) != 0)
		pa_bonus(s);
	else if (ft_strncmp(line, "pb\n", 2147483647) != 0)
		pb_bonus(s);
	else if (ft_strncmp(line, "sa\n", 2147483647) != 0)
		sa_bonus(s);
	else if (ft_strncmp(line, "sb\n", 2147483647) != 0)
		sb_bonus(s);
	else if (ft_strncmp(line, "ss\n", 2147483647) != 0)
		ss_bonus(s);
	else
		return (write(2, "Error\n", 6), exit(0));
}

int	main(int ac, char **av)
{
	t_stack	*s;

	if (ac == 1)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	s = malloc(sizeof(t_stack));
	s->len_b = 0;
	s->sortedtab = 0;
	if (parser_bonus(av, s) == 1)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	reader(s);
	if (check_sorted(s) == 0)
		return (write(2, "KO\n", 3));
	return (0);
}
