/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:24:20 by lgrossi           #+#    #+#             */
/*   Updated: 2023/09/26 17:42:38 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static	void	pa_helper(t_stack	*a, int	*new)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		new[i] = a->array[i];
		i++;
	}
}

void	push(t_stack *a, t_stack *b)
{
	int	*new_a;
	int	*new_b;
	int	i;

	i = 0;
	if (b->top <= 0)
		return ;
	new_a = calloc(sizeof(int) * (a->top + 2), 1);
	new_b = calloc (sizeof(int) * b->top, 1);
	new_a[a->top] = b->array[b->top - 1];
	pa_helper(a, new_a);
	while (i < b->top - 1)
	{
		new_b[i] = b->array[i];
		i++;
	}
	free (a->array);
	free (b->array);
	a->top++;
	b->top--;
	a->array = new_a;
	b->array = new_b;
}

void	r_d_d_m(t_stack *a, int x, t_stack *b, int y)
{
	int	n;
	int	i;

	n = up_or_down(*a, x);
	i = up_or_down(*b, y);
	if (n == i)
	{
		if (n == 0)
			pa(b, a);
		else if (n > 0)
			rr(a, b);
		else
			rrr(a, b);
	}
	else
	{
		if (n > 0)
			rb(a);
		if (n < 0)
			rrb(a);
		if (i > 0)
			ra(b);
		else
			rra(b);
	}
}
