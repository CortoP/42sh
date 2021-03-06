/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:56 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:56 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			i_tmp;

	if (!s2 || ft_strlen(s2) == 0)
		return ((char*)s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		i_tmp = i;
		while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i_tmp]);
		i = i_tmp + 1;
		j = 0;
	}
	return (NULL);
}
