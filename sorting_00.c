/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:58:08 by lgrossi           #+#    #+#             */
/*   Updated: 2023/09/25 20:23:42 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_or_down(t_stack a, int n)
{
	int	i;

	i = 0;
	while (a.array[i] != n && i < a.top)
		i++;
	if (a.top == i + 1)
		return (0);
	if (a.top - (i + 1) < i + 1)
		return (1);
	else
		return (-1);
}

int	moves_to_the_top(t_stack a, int n)
{
	int	i;

	i = 0;
	while (a.array[i] != n && i < a.top)
		i++;
	if (a.top == i + 1)
		return (0);
	if (a.top - (i + 1) < i + 1)
		return (a.top - (i + 1));
	else
		return (i + 1);
}

int	how_many_moves(int n, t_stack a, t_stack b)
{
	int	moves;
	int	up_a;
	int	up_b;

	moves = 0;
	up_a = moves_to_the_top(a, n);
	up_b = moves_to_the_top(b, i_p(b, n));
	if (up_or_down(a, n) == up_or_down(b, i_p(b, n)) && up_a >= up_b)
		return (up_a + 1);
	else if (up_or_down(a, n) == up_or_down(b, i_p(b, n)) && up_a < up_b)
		return (up_b + 1);
	else
		moves += up_a + up_b + 1;
	return (moves);
}

int	rev_how_many_moves(int n, t_stack a, t_stack b)
{
	int	moves;
	int	up_a;
	int	up_b;

	moves = 0;
	up_a = moves_to_the_top(a, n);
	up_b = moves_to_the_top(b, p_i(b, n));
	if (up_or_down(a, n) == up_or_down(b, p_i(b, n)) && up_a >= up_b)
		return (up_a + 1);
	else if (up_or_down(a, n) == up_or_down(b, p_i(b, n)) && up_a < up_b)
		return (up_b + 1);
	else
		moves += up_a + up_b + 1;
	return (moves);
}

void	d_d_m(t_stack *a, int x, t_stack *b, int y)
{
	int	n;
	int	i;

	n = up_or_down(*a, x);
	i = up_or_down(*b, y);
	if (n == i)
	{
		if (n == 0)
			pb(a, b);
		else if (n > 0)
			rr(a, b);
		else
			rrr(a, b);
	}
	else
	{
		if (n > 0)
			ra(a);
		if (n < 0)
			rra(a);
		if (i > 0)
			rb(b);
		if (i < 0)
			rrb(b);
	}
}
