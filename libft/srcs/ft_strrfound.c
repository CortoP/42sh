/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrfound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:58 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:58 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strrfound(const char *src, int value)
{
	size_t			index;
	int				res;

	index = 0;
	res = -1;
	while (src[index] != '\0')
	{
		if (src[index] == (char)value)
			res = index;
		index++;
	}
	return (res);
}
