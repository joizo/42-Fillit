/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:22:01 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 19:56:19 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*s2;
	char	*s3;
	size_t	len;

	if (s == NULL)
		return (NULL);
	s2 = (char *)s;
	i = 0;
	while (s2[i] && ((s2[i] == ' ') || (s2[i] == '\n') || (s2[i] == '\t')))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	len = ft_strlen(s2) - 1;
	while ((s2[len] == ' ') || (s2[len] == '\n') || (s2[len] == '\t'))
		len--;
	len = len - i + 1;
	s3 = ft_strnew(len);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s2 + i, len);
	return (s3);
}
