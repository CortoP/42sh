/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:32 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:32 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strcat(char *dst, const char *src)
{
	size_t			index_dst;
	size_t			index_src;

	index_dst = 0;
	index_src = 0;
	while (dst[index_dst] != '\0')
		index_dst++;
	while (src[index_src] != '\0')
		dst[index_dst++] = src[index_src++];
	dst[index_dst] = '\0';
	return (dst);
}
