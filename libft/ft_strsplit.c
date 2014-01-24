/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:46:41 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/19 15:49:53 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *chain, char sep)
{
	int	chnum;
	int	bool;

	chnum = 0;
	bool = 0;
	while (*chain != '\0')
	{
		if (*chain != sep && bool == 0)
		{
			chnum++;
			bool = 1;
		}
		else if (*chain == sep && bool == 1)
			bool = 0;
		chain++;
	}
	return (chnum);
}

static int		ft_endstr(char const *chain, char sep)
{
	while (*chain != '\0' && *chain == sep)
		chain++;
	if (*chain == '\0')
		return (1);
	return (0);
}

static int		ft_strlensplit(char const *chain, char c)
{
	int	i;

	i = 0;
	while (chain[i] != c && chain[i] != '\0')
		i++;
	return (i);
}

static char		*ft_feeltab(char const *chain, int len)
{
	int			i;
	char		*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		copy[i] = chain[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char			**ft_strsplit(char const *s, char c)
{
	int			chnum;
	int			i;
	char		**tab;
	char		*cmp_NULL;

	i = 0;
	cmp_NULL = NULL;
	if (cmp_NULL != s)
	{
		chnum = ft_count(s, c);
		tab = (char **)malloc(sizeof(char *) * (chnum + 1));
		while (*s != '\0' && !ft_endstr(s, c))
		{
			while (*s == c && *s != '\0')
				s++;
			tab[i] = ft_feeltab(s, ft_strlensplit(s, c));
			i++;
			while (*s != c && *s != '\0')
				s++;
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
