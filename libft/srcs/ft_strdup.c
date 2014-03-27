/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:37 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:37 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strdup(const char *src)
{
	char			*dst;

	dst = NULL;
	if (src != NULL)
	{
		dst = (char*)malloc(sizeof(*dst) * (ft_strlen(src) + 1));
		if (dst != NULL)
			ft_strcpy(dst, src);
	}
	return (dst);
}
