/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:03:25 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:03:25 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				main(int ac, char **av, char **env)
{
	t_sh		*sh;
	int			stop;

	create_env(env);
	env = add_builtin_pid(env);
	set_signal();
	if (ac > 1)
		(void)av;
	else
	{
		stop = 0;
		sh = get_sh(&stop);
		set_terminal(sh);
		while (!stop)
		{
			sh->ft_stdin = dup(STDIN_FILENO);
			sh->ft_stdout = dup(STDOUT_FILENO);
			start_sh(sh);
			ft_putenv("PID_EXECV", NULL);
		}
	}
	return (0);
}
