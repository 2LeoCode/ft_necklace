/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 22:24:50 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/20 20:56:03 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <necklace.h>

size_t ft_strlen(const char * s)
{
	size_t i = 0;

	while (s[i])
		i++;
	return (i);
}

int ft_strcmp(const char * s1, const char * s2)
{
	while ((*s1 || *s2) && (*s1 == *s2))
		s1++, s2++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char * ft_strcpy(char * dst, const char * src)
{
	int i = -1;

	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

char * ft_strdup(const char * s)
{
	size_t len = ft_strlen(s);
	char * dup = (char*)malloc(sizeof(char) * (len + 1));

	return (dup ? ft_strcpy(dup, s) : NULL);
}
