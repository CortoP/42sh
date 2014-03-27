/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:45 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:45 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t			ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t		dst_len;
	size_t		res;
	size_t		i;
	size_t		j;

	dst_len = ft_strlen(dst);
	res = dst_len + ft_strlen(src);
	i = 0;
	j = 0;
	if (len <= dst_len)
		res = res - (dst_len - len);
	else
	{
		len = len - (dst_len + 1);
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && j < len)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (res);
}
