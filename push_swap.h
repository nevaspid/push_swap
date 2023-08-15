/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:01:54 by gloms             #+#    #+#             */
/*   Updated: 2023/08/14 22:15:07 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a;
	int *b;
	int	*sortedtab;
	int	len_a;
	int len_b;
}	t_stack;

typedef struct s_costs
{
	int	ra_tmp2;
	int	rb_tmp2;
	int	rr_tmp2;
	int	rra_tmp2;
	int	rrb_tmp2;
	int	rrr_tmp2;
	int	total_tmp2;
	int	ra_tmp;
	int	rb_tmp;
	int	rr_tmp;
	int	rra_tmp;
	int	rrb_tmp;
	int	rrr_tmp;
	int	total_tmp;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_costs;

int		ft_atoi(char *str, int *atoi_error);
int		parser(char **av, t_stack *stack);
int		ft_isdigit(char *str, int i);
char	**ft_split(const char *s, char c);
size_t	wordcount(const char *s, char c);
int		check_space(char **av);
int		arg_count(char **av, int *atoi_error, t_stack *stack);
int		check_doubles(t_stack *stack);
int		check_in_int(t_stack *stack);
int		check_sorted(t_stack *stack);
void	print_stacks(t_stack *stack);

/* MOVES */
void small_to_top(t_stack *s);
void big_to_top(t_stack *s);
void pa(t_stack *stack);
void pb(t_stack *stack);
void ss(t_stack *stack);
void sa(t_stack *stack);
void sb(t_stack *stack);
void ra(t_stack *stack, int rr);
void rb(t_stack *stack, int rr);
void rr(t_stack *stack);
void rra(t_stack *stack, int rrr);
void rrb(t_stack *stack, int rrr);
void rrr(t_stack *stack);

/* SORTING */
int		find_biggest(t_stack *s);
int		find_smallest(t_stack *s);
void	lilsort(t_stack *s, int sort);

/* COST CALCULATION */
void	individual_cost(int index_a, int index_b, t_stack *s, t_costs *c);

#endif
