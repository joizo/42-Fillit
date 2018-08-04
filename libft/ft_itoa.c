/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:22:36 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/02 16:15:13 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s1;
	int		len;
	int		k;

	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_c_int_num(n);
	if ((s1 = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	s1[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		k = 1;
	}
	while (len--)
	{
		s1[len] = n % 10 + 48;
		n = n / 10;
	}
	if (k == 1)
		s1[0] = '-';
	return (s1);
}
