/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cmd_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:02:15 by grebett           #+#    #+#             */
/*   Updated: 2014/03/27 14:02:15 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_dlst_cmd			*ft_dlst_cmd_new(char c)
{
	t_dlst_cmd		*new;

	new = (t_dlst_cmd *)malloc(sizeof(t_dlst_cmd));
	new->c = c;
	new->next = (t_dlst_cmd *)malloc(sizeof(t_dlst_cmd));
	new->prev = (t_dlst_cmd *)malloc(sizeof(t_dlst_cmd));
	return (new);
}
