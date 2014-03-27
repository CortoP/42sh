/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:05:47 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:05:47 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				**ft_ctabcpy(char **dst, char **src)
{
	size_t			index;

	index = 0;
	while (src[index])
	{
		ft_strcpy(dst[index], src[index]);
		index++;
	}
	dst[index] = NULL;
	return (dst);
}
