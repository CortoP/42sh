/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:42 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:42 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_striter(char *str, void (*f)(char *))
{
	size_t		index;

	if (str && f)
	{
		index = 0;
		while (str[index] != '\0')
		{
			(*f)(str + index);
			index++;
		}
	}
}
