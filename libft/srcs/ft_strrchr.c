/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:57 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:57 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strrchr(const char *src, int value)
{
	size_t			index;
	char			*res;

	index = 0;
	res = NULL;
	while (src[index] != '\0')
	{
		if (src[index] == (char)value)
			res = (char*)&src[index];
		index++;
	}
	if ((char)value == '\0')
		return ((char*)&src[index]);
	return (res);
}
