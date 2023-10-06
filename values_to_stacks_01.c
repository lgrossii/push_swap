/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_to_stacks_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:00:58 by lgrossi           #+#    #+#             */
/*   Updated: 2023/10/03 18:48:15 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	values(int ac, char	**av, t_stack *a, t_stack *b)
{
	int		i;
	char	**splitted;

	i = 0;
	if (!checker(ac, av))
		exit (1);
	if (ac < 2)
		exit (0);
	if (ac == 2)
	{
		splitted = new_ft_split(av[1]);
		values_to_t_stack(splitted, a);
		while (splitted[i])
		{
			free (splitted[i]);
			i++;
		}
		free (splitted);
	}
	else
		values_to_t_stack(++av, a);
	b->top = 0;
	b->array = ft_calloc(sizeof(int), 1);
}

int	array_sorted(int *array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[j])
	{
		while (array[i])
		{
			if (i < j && array[i] < array[j])
				return (0);
			if (i > j && array[i] > array[j])
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

void	frees(t_stack *a, t_stack *b)
{
	free(a->array);
	free(b->array);
}
