/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necklace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 22:14:27 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/20 20:56:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <necklace.h>

int ft_necklace(const char * s1, const char * s2)
{
	size_t len = ft_strlen(s1);
	char * dup = ft_strdup(s1);
	char c;

	if (!dup)
		return (-1);
	if (len != ft_strlen(s2))
		return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
	for (size_t i = 0; i < len; i++)
	{
		c = *dup;
		for (size_t j = 0; j < (len - 1); j++)
			dup[j] = dup[j + 1];
		dup[len - 1] = c;
		if (!ft_strcmp(dup, s2))
			return (1);
	}
	return (0);
}
