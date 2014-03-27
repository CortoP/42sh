/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:05:48 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:05:48 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
char		**ft_ctabdel(char **tab, size_t i)
{
	char	**new_env;
	size_t	j;

	new_env = (char **)malloc(sizeof(char *) * ft_ctablen(tab));
	j = 0;
	while (j < i && tab[j])
	{
		new_env[j] = tab[j];
		j++;
	}
	while (tab[j + 1])
	{
		new_env[j] = tab[j + 1];
		j++;
	}
	new_env[j] = NULL;
	return (new_env);
}
