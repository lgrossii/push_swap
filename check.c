/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:02 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/04 16:18:18 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_t_stack(t_stack a, int j)
{
	int	i;

	i = 0;
	if (j == 1)
		printf("t_stack a : \n");
	else
		printf ("t_stack b : \n");
	while (a.array[i])
		i++;
	if (i == 0)
		return ;
	i--;
	while (i >= 0)
	{
		printf(" %d|        %d \n", i, a.array[i]);
		i--;
	}
}

long	ft_atoi_long(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((sign) * (result));
}

int	check_limits(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi_long(s[i]) > 2147483647 || ft_atoi_long(s[i]) < -2147483647)
			return (-1);
		i++;
	}
	return (1);
}
