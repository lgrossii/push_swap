/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_to_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:36:38 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/10/04 16:00:47 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	values_to_t_stack(char	**values, t_stack *a)
{
	int	tot;
	int	i;

	tot = 0;
	i = 0;
	while (values[tot] != NULL)
		tot++;
	a->array = ft_calloc (sizeof(int ) * (tot + 1), 1);
	if (!a->array)
		return ;
	a->top = tot;
	while (tot > 0)
	{
		a->array[tot -1] = ft_atoi(values[i]);
		i++;
		tot--;
	}
}

static int	new_words_count(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] && s[i] != 0)
			words++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
	}
	return (words);
}

static int	new_let_count(char const *s, int i)
{
	int	letters;

	letters = 0;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
	{
		letters++;
		i++;
	}
	return (letters);
}

static void	new_s_create(char *s1, char const *s, int i)
{
	int	j;

	j = 0;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
	{
		s1[j] = s[i]; 
		i++;
		j++;
	}
	s1[j] = 0;
}

char	**new_ft_split(char const *s)
{
	char	**s1;
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
	s1 = (char **)malloc((new_words_count(s) + 1) * (sizeof(char *)));
	if (!s1 || !s)
		return (NULL);
	while (words < new_words_count(s))
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		s1[words] = (char *)malloc(new_let_count(s, i) + 1);
		new_s_create(s1[words], s, i);
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
			i++;
		words++;
	}
	s1[words] = 0;
	return (s1);
}
