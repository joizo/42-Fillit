/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:30:09 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 20:05:38 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_i;
	unsigned char	*s2_i;
	size_t			i;

	i = 0;
	if (!s1 && !s2 && !n)
		return (0);
	s1_i = (unsigned char *)s1;
	s2_i = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_i[i] - s2_i[i] != 0)
			return (s1_i[i] - s2_i[i]);
		i++;
	}
	return (0);
}
