/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:43 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:43 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (str && f)
	{
		index = 0;
		while (str[0] != '\0')
		{
			(*f)(index, str);
			str++;
			index++;
		}
	}
}
