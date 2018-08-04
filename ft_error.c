/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 03:07:59 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/08/04 19:20:15 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_show_usage(void)
{
	ft_putstr("usage: fillit [input_file]\n");
	exit(1);
}
