/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:07:04 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:07:04 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_toupper(int value)
{
	if (value < 0141 || value > 0172)
		return (value);
	return (value - 0141 + 0101);
}
