/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs_putchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:04:24 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/27 14:04:24 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					tputs_putchar(int c)
{
	return (write(2, &c, 1));
}
