/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:52:05 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/04 16:20:19 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	legit_values(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	double_one(char	*s, char	*str)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != str[i])
			return (1);
		i++;
	}
	if (s[i] != str[i])
		return (1);
	else
		return (0);
}

int	check_values(char	**values)
{
	int	doppio;
	int	i;
	int	j;

	doppio = 0;
	i = 0;
	j = 0;
	while (values[i])
	{
		if (!legit_values(values[i]))
			return (0);
		while (values[j])
		{
			if (!double_one(values[i], values[j]))
				doppio++;
			j++;
		}
		if (doppio > 1)
			return (0);
		j = 0;
		doppio = 0;
		i++;
	}
	return (1);
}

static void	free_splitted(char	**values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free (values[i]);
		i++;
	}
	free (values);
}

int	checker(int ac, char **av)
{
	int		n;
	char	**values;
	int		j;

	j = 0;
	n = 0;
	if (ac == 2)
	{
		values = new_ft_split(av[1]);
		j = check_limits(values);
		n = check_values(values);
		free_splitted(values);
	}
	else
	{
		n = check_values(++av);
		j = check_limits(av);
	}
	if (n == 0 || j == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
		return (1);
}
