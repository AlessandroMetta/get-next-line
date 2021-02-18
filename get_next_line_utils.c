/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:57:37 by ametta            #+#    #+#             */
/*   Updated: 2021/02/18 16:01:50 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != c && s[i] != '\0')
        i++;
    if (s[i] == c)
        return((char *)s + i);
    return(NULL);
}

char    *ft_strdup(const char *s1)
{
    int i;
    char    *cpy;

    i = 0;
    while (s1[i++] != '\0')
        ;
    if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
        return(NULL);
    while (i-- >= 0)
        cpy[i] = s1[i];
    return(cpy);
}

char    *ft_strjoin(char const *str1, char const *str2)
{
    int i;
    int j;
    char    *cat;

    i = j = 0;
    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0')
        j++;
    if (!(cat = (char *)malloc(sizeof(char) * (i + j + 1))))
        return(NULL);
    while (j-- >= 0)
        cat[i + j] = str2[j];
    while (i-- >= 0)
        cat[i] = str1[i];
    return(cat);
}