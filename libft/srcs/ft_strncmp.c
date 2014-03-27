/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:51 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:51 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t			k;

	k = 0;
	if (len)
	{
		while (str1[k] != '\0' && k < len)
		{
			if (str1[k] != str2[k])
			{
				if (str1[k] < str2[k])
					return (-1);
				return (1);
			}
			k++;
		}
		k--;
		if (str1[k] != str2[k])
		{
			if (str1[k] < str2[k])
				return (-1);
			return (1);
		}
	}
	return (0);
}
