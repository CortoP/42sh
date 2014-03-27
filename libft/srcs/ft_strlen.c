/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:46 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:46 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t			ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	if (str)
	{
		while (str[index])
			index++;
	}
	return (index);
}
