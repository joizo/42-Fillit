/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:43:27 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 20:10:52 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}