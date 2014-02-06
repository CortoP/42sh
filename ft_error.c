/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:51:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 13:42:44 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

void		ft_error(int error, char *name)
{
    if (error == CMD_NOT_FOUND)
        write(2, "ft_sh: command not found: ", 26);
    else if (error == PER_DEN)
        write(2, "cd: permission denied: ", 23);
    else if (error == N_F_D)
        write(2, "cd: no such file or directory: ", 31);
    else if (error == NOT_DIR)
        write(2, "cd: not a directory: ", 21);
    if (error == 1 || error == 2 || error == 3 || error == 4)
    {
        write(2, name, ft_strlen(name));
        write(2, "\n", 1);
    }	
}
