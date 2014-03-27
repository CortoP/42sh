/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:16 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:16 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memset(void *to_set, int value, size_t len)
{
	unsigned char	*p_to_set;
	size_t			k;

	p_to_set = (unsigned char*)to_set;
	k = 0;
	while (k < len)
		p_to_set[k++] = (unsigned char)value;
	return (to_set);
}
