/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:42:43 by ametta            #+#    #+#             */
/*   Updated: 2021/02/19 12:52:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_strchr(const char *str, int needle)
{
	int	count;

	count = 0;
	while (str[count] != '\0' && str[count] != needle)
		count++;
	if (str[count] == needle)
		return ((char *)str + count);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		count;
	char	*cpy;

	count = 0;
	while (str[count] != '\0')
		count++;
	cpy = (char *)malloc(sizeof(char) * count);
	while (count >= 0)
	{
		cpy[count] = str[count];
		count--;
	}
	return (cpy);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		count1;
	int		count2;
	char	*cpy;

	count1 = 0;
	count2 = 0;
	while (str1[count1] != '\0')
		count1++;
	while (str2[count2] != '\0')
		count2++;
	cpy = (char *)malloc(sizeof(char) * count1 + count2);
	while (count2 >= 0)
	{
		cpy[count1 + count2] = str2[count2];
		count2--;
	}
	while (count1-- >= 0)
		cpy[count1] = str1[count1];
	return (cpy);
}
