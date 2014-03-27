/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:03:33 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:03:33 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <stdlib.h>
#include <term.h>

void	sh_quit(void)
{
	sh_reset_termios();
	set_winstruct(NULL, 1);
	tputs(tgetstr("ei", NULL), 0, tputchar);
	_exit(0);
}
