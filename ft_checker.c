/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:57:54 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/07/22 17:58:00 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_checker(char *str)
{
	if (ft_tetr_elm_check(str) == 0 || ft_comm_tetr(str) == 0 ||
	 ft_tetr_valid_check(str) == 0 || ft_resh_check(str) == 0 ||
	 ft_tetr_count_check(str) < 0 || ft_tetr_count_check(str) > 26 ||
	 ft_sym_row_check(str) == 0)
		return (0);
	return (1);
}
