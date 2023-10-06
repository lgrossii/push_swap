/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:47:12 by lgrossi           #+#    #+#             */
/*   Updated: 2023/10/03 18:37:37 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	a_is_not_sorted(t_stack *a)
{
	if (!is_sorted(*a))
	{
		if (a->array[1] == max_number(*a))
			rra(a);
		else if (a->array[2] == max_number(*a))
			ra(a);
		if (!(is_sorted(*a)))
			sa(a);
	}
}

void	push_2_in_b(t_stack *a, t_stack *b)
{
	while (a->top > 3 && b->top < 2)
		pb(a, b);
}

void	swap(t_stack	*a)
{
	int	temp;

	if (a->top <= 1)
		return ;
	temp = a->array[a->top - 2];
	a->array[a->top - 2] = a->array[a->top - 1];
	a->array[a->top - 1] = temp;
}

void	rotate(t_stack *a)
{
	int	i;
	int	temp;

	i = a->top - 1;
	if (a->top <= 1)
		return ;
	temp = a->array[a->top - 1];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
}

void	rev_rotate(t_stack *a)
{
	int	i;
	int	temp;

	temp = a->array[0];
	i = 0;
	if (a->top <= 1)
		return ;
	while (i < a->top - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = temp;
}
