/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:09 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:09 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	size_t			k;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	k = 0;
	while (k < len)
	{
		if ((*p_dst++ = *p_src++) == c)
			return (p_dst);
		k++;
	}
	return (NULL);
}
