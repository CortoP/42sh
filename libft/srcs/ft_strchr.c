/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:33 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:33 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strchr(const char *src, int value)
{
	size_t			index;

	if (!src)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		if (src[index] == (char)value)
			return ((char*)&src[index]);
		index++;
	}
	if ((char)value == '\0')
		return ((char*)&src[index]);
	return (NULL);
}
