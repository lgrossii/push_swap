/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:34:30 by lgrossi           #+#    #+#             */
/*   Updated: 2023/09/25 20:25:09 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	min_number(t_stack a)
{
	int	i;
	int	number;

	i = 0;
	number = 147483648;
	while (i < a.top)
	{
		if (a.array[i] < number)
			number = a.array[i];
		i++;
	}
	return (number);
}

int	max_number(t_stack a)
{
	int	n;
	int	max;

	max = -2147483648;
	n = 0;
	while (n < a.top)
	{
		if (a.array[n] > max)
			max = a.array[n];
		n++;
	}
	return (max);
}

int	is_sorted(t_stack a)
{
	if (a.array[0] > a.array[1] && a.array[1] > a.array[2])
	{
		if (a.array[0] > a.array[2])
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
