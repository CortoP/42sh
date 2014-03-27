/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctablen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:05:51 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:05:51 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_ctablen(char **ctab)
{
	size_t			index;

	index = 0;
	if (ctab)
	{
		while (ctab[index])
			index++;
	}
	return (index);
}
