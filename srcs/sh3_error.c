/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:03:30 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:03:30 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
void	sh_error_quit(char	*str)
{
	ft_putstr_fd("error :", 2);
	ft_putendl_fd(str, 2);
	sh_quit();
}
