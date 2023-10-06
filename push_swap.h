/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:37:18 by lgrossi           #+#    #+#             */
/*   Updated: 2023/10/04 16:17:28 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int	*array;
	int	top;
}	t_stack;

void	sa(t_stack *a);

void	sb(t_stack *b);

void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *a);

void	rb(t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);

void	rrb(t_stack *b);

void	rrr(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

int		max_number(t_stack a );

int		min_number(t_stack a);

int		up_or_down(t_stack a, int n);

void	d_d_m(t_stack *a, int x, t_stack *b, int y);

int		i_p(t_stack b, int n);//

int		moves_to_the_top(t_stack a, int n);

int		how_many_moves( int n, t_stack a, t_stack b);

int		b_n_t_p(t_stack a, t_stack b);

int		p_i(t_stack a, int n);//

int		rev_how_many_moves( int n, t_stack a, t_stack b);

int		r_b_n(t_stack a, t_stack b);//

void	values_to_t_stack(char	**values, t_stack *a);

char	**new_ft_split(char const *s);

int		is_sorted(t_stack a);

void	a_is_not_sorted(t_stack *a);

void	push_2_in_b(t_stack *a, t_stack *b);

void	swap(t_stack	*a);

void	rotate(t_stack *a);

void	rev_rotate(t_stack *a);

void	push(t_stack *a, t_stack *b);

void	r_d_d_m(t_stack *a, int x, t_stack *b, int y);

int		checker(int ac, char **av);

int		check_values(char	**values);

int		double_one(char	*s, char	*str);

int		legit_values(char *s);

void	print_t_stack(t_stack a, int j);

void	values(int ac, char	**av, t_stack *a, t_stack *b);

int		array_sorted(int *array);

void	frees(t_stack *a, t_stack *b);

long	ft_atoi_long(const char *str);

int		check_limits(char **s);
#endif
