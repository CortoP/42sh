/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_histo_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:02:22 by grebett           #+#    #+#             */
/*   Updated: 2014/03/27 14:02:22 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_dlst_histo		*ft_dlst_histo_new(t_cmd *cmd)
{
	t_dlst_histo	*new;

	new = (t_dlst_histo *)malloc(sizeof(t_dlst_histo));
	new->cmd = cmd;
	new->next = (t_dlst_histo *)malloc(sizeof(t_dlst_histo));
	new->prev = (t_dlst_histo *)malloc(sizeof(t_dlst_histo));
	return (new);
}
