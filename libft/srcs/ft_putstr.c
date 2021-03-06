/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:25 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:25 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_putstr(const char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	else
		write(1, "(null)", 6);
}
