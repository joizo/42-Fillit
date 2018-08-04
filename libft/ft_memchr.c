/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:09:05 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 20:05:26 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_i;
	size_t			i;

	i = 0;
	s_i = (unsigned char *)s;
	while (i < n)
	{
		if (s_i[i] == (unsigned char)c)
			return (&s_i[i]);
		i++;
	}
	return (NULL);
}
