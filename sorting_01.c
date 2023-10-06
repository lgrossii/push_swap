/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:10:16 by lgrossi           #+#    #+#             */
/*   Updated: 2023/09/30 18:56:24 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	b_n_t_p(t_stack a, t_stack b)
{
	int	i;
	int	n;
	int	n_moves;

	i = 0;
	n = 0;
	n_moves = 147483648;
	while (i < a.top)
	{
		if (how_many_moves(a.array[i], a, b) < n_moves)
		{
			n_moves = how_many_moves(a.array [i], a, b);
			n = a.array[i];
		}
		i++;
	}
	return (n);
}

int	r_b_n(t_stack a, t_stack b)
{
	int	i;
	int	n;
	int	n_moves;

	i = 0;
	n = 0;
	n_moves = 147483648;
	while (i < a.top)
	{
		if (rev_how_many_moves(a.array[i], a, b) < n_moves)
		{
			n_moves = rev_how_many_moves(a.array[i], a, b);
			n = a.array[i];
		}
		i++;
	}
	return (n);
}

int	i_p(t_stack b, int n)
{
	int	i;
	int	number;

	i = 0;
	number = -2147483648;
	while (i < b.top)
	{
		if (b.array[i] < n && b.array[i] > number)
			number = b.array[i];
		i++;
	}
	if (number == -2147483648)
		return (max_number(b));
	return (number);
}

int	p_i(t_stack a, int n)
{
	int	i;
	int	number;

	i = 0;
	number = 2147483647;
	while (i < a.top)
	{
		if (a.array[i] > n && a.array[i] < number)
			number = a.array[i];
		i++;
	}
	if (number == 2147483647)
		return (min_number(a));
	return (number);
}
