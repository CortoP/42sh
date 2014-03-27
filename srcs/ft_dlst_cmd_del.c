/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cmd_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:10:24 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:10:29 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				ft_dlst_cmd_del(t_cmd *cmd)
{
	t_dlst_cmd		*current;
	int				i;

	current = *(cmd->adlst);
	i = 0;
	while (i < cmd->size)
	{
		ft_dlst_cmd_delone(current);
		current = current->next;
		i++;
	}
	free(cmd->adlst);
	free(cmd);
}
