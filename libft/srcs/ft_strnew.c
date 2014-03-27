/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:54 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:54 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strnew(size_t size)
{
	char		*str;
	size_t		index;

	if (!size)
		return (NULL);
	index = 0;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str != NULL)
	{
		while (index < size)
		{
			str[index] = '\0';
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
