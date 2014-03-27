/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_get_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:03:39 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:03:39 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>

static t_k_type				sh_key_is_simple(t_usent *us)
{
	static t_simp_key		s_k[] = KEY;
	int						i;

	i = 0;
	while (s_k[i].k_type != K_NONE)
	{
		if (s_k[i].c == us->buf[0])
			return (s_k[i].k_type);
		i++;
	}
	return (K_NONE);
}

static t_k_type				sh_key_is_sequence(t_usent *us)
{
	static t_simp_key		s_k[] = KEY_BIS;
	int						i;

	i = -1;
	while (s_k[++i].k_type != K_NONE)
	{
		if (s_k[i].c == us->buf[2])
			return (s_k[i].k_type);
	}
	return (K_NONE);
}

t_k_type					sh_key_get(t_usent *us)
{
	if (us->buf[1] == 0 && us->buf[2] == 0)
		return (sh_key_is_simple(us));
	if (us->buf[0] == 27 && us->buf[1] == 91)
		return (sh_key_is_sequence(us));
	return (K_NONE);
}
