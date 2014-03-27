/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:02 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:02 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstadd(t_list **alst, t_list *new_link)
{
	t_list			**save;

	if (!alst)
		*alst = new_link;
	save = alst;
	new_link->next = *save;
	alst = &new_link;
}
