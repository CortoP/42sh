/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cmd_delpos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:02:06 by grebett           #+#    #+#             */
/*   Updated: 2014/03/27 14:02:06 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				ft_dlst_cmd_delpos(t_cmd *cmd, int pos)
{
	t_dlst_cmd		*current;
	t_dlst_cmd		*cur_prev;
	t_dlst_cmd		*cur_next;
	int				i;

	current = *(cmd->adlst);
	i = 0;
	while (i++ < pos)
		current = current->next;
	cur_prev = current->prev;
	cur_next = current->next;
	cur_prev->next = cur_next;
	cur_next->prev = cur_prev;
	if (!pos)
		*(cmd->adlst) = cur_next;
	cmd->size = cmd->size - 1;
}
