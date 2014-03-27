/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:59 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:59 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			is_value(char *values, char c)
{
	int				i;

	i = 0;
	while (values[i])
	{
		if (values[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int			get_nbr(const char *str, char *values)
{
	int				i;
	int				nbr;

	nbr = 1;
	i = 0;
	while (str[i] && str[i + 1])
	{
		if (is_value(values, str[i]))
		{
			if (!is_value(values, str[i + 1]))
				nbr++;
		}
		i++;
	}
	return (nbr);
}

char				**ft_strsplit(const char *str, char *values)
{
	char			**split;
	int				nbr;
	int				i;
	int				j;
	int				s;

	nbr = get_nbr(str, values);
	split = (char **)malloc(sizeof(char *) * (nbr + 1));
	i = 0;
	s = 0;
	while (str[i] && s < nbr)
	{
		while (is_value(values, str[i]))
			i++;
		j = i;
		while (str[j] && !is_value(values, str[j]))
			j++;
		split[s] = ft_strsub(str, i, j - i);
		s++;
		i = j;
	}
	split[s] = NULL;
	return (split);
}
