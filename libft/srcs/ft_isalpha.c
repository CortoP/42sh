/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:05:58 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:05:58 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isalpha(int value)
{
	if (value < 0101 || value > 0132)
	{
		if (value < 0141 || value > 0172)
			return (0);
	}
	return (1);
}
