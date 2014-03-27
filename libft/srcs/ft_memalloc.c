/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:08 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:08 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memalloc(size_t size)
{
	void			*mem;

	mem = NULL;
	mem = (void*)malloc(size);
	if (!mem)
		return (NULL);
	return (mem);
}
