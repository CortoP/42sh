/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:06:03 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:06:03 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstaddend(t_list **alst, t_list *new)
{
	t_list			*save;
	t_list			*current;

	save = *alst;
	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
	*alst = save;
}
