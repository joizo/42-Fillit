/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:31:02 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/02 16:17:11 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t d2;

	d2 = ft_strlen(d);
	if (n <= d2)
		return (ft_strlen(s) + n);
	ft_strncat(d, s, (n - d2 - 1));
	return (d2 + ft_strlen(s));
}
