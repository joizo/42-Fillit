/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:22:22 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/02 20:13:40 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_d(const char *s, int start_i, char n)
{
	int len;

	len = 0;
	while (s[start_i] != n && s[start_i])
	{
		len++;
		start_i++;
	}
	return (len);
}

static int	ft_w_count(char *s, char c)
{
	int i;
	int w_count;

	i = 0;
	w_count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			w_count++;
		i++;
	}
	return (w_count);
}

static char	**ft_mal_split(char *s1, char c)
{
	int		len;
	char	**s2;

	len = ft_w_count(s1, c);
	s2 = (char **)malloc(sizeof(char *) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	s2[len] = NULL;
	return (s2);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	*s1;
	char	**s2;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	s1 = (char *)s;
	if ((s2 = ft_mal_split(s1, c)) == NULL)
		return (NULL);
	while (s1[i])
	{
		while (s1[i] != c && s1[i])
		{
			s2[j++] = ft_strsub(s1, i, ft_strlen_d(s1, i, c));
			i = i + ft_strlen_d(s1, i, c);
		}
		if (s1[i++] == '\0')
			break ;
		while (s1[i] == c && s1[i])
			i++;
	}
	return (s2);
}
