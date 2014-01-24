/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 11:25:26 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/23 18:22:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

char			**ft_split_trim(char *str, char c)
{
	char		**splitted_str;
	int			i;

	splitted_str = ft_strsplit(str, c);

	i = 0;
	while (splitted_str[i])
	{
		splitted_str[i] = ft_strtrim(splitted_str[i]);
		i++;
	}
	return (splitted_str);
}


t_cmd				*ft_get_separated_cmd(char **s_semic_split)
{
	int				i;
	t_cmd			*cmd;
	t_cmd			*first;

	cmd = ft_init_cmd(s_semic_split[0], CMD);
	first = cmd;
	i = 1;
	while (s_semic_split[i])
	{
		cmd->next = ft_init_cmd(s_semic_split[i], CMD);
		cmd = cmd->next;
		i++;
	}
	free (s_semic_split);
	return (first);
}
