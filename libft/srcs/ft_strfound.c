/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:40 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:40 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strfound(const char *src, int value)
{
	int				index;

	if (!src)
		return (0);
	index = 0;
	while (src[index] != '\0')
	{
		if (src[index] == (char)value)
			return (index);
		index++;
	}
	if ((char)value == '\0')
		return (index);
	return (0);
}
