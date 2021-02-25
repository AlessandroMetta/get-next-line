/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:09:33 by ametta            #+#    #+#             */
/*   Updated: 2021/02/25 11:09:40 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2)
		+ 1)))
		return (NULL);
	while (s1[i] != 0)
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		str[j++] = s2[i++];
	str[j] = s2[i];
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!(cpy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] != 0)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}
