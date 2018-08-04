/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:54:40 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/04/27 23:39:43 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mass;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	mass = ft_strnew(ft_strlen(s));
	if (mass == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mass[i] = f(s[i]);
		i++;
	}
	return (mass);
}
