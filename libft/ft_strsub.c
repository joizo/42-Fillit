/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:56:07 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 20:17:17 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	s2 = (char *)malloc((sizeof(char) * len) + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
