/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:48 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:48 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strmap(const char *str, char (*f)(char))
{
	char		*new_str;
	size_t		index;

	new_str = NULL;
	if (str && f)
	{
		new_str = (char*)malloc(sizeof(*new_str) * (ft_strlen(str) + 1));
		index = 0;
		while (str[index] != '\0')
		{
			new_str[index] = f(str[index]);
			index++;
		}
		new_str[index] = '\0';
	}
	return (new_str);
}
