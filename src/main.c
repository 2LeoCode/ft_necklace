/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 22:00:39 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/20 20:56:13 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <necklace.h>
#include <stdio.h>

void ft_necklace_test(const char * s1, const char * s2)
{
	printf("ft_necklace (\"%s\", \"%s\") == %d\n", s1, s2, ft_necklace (s1, s2));
}

int main(void)
{
	ft_necklace_test("nicole", "icolen");
	ft_necklace_test("nicole", "lenico");
	ft_necklace_test("nicole", "coneli");
	ft_necklace_test("aabaaaaabaab", "aabaabaabaaa");
	ft_necklace_test("abc", "cba");
	ft_necklace_test("xxyyy", "xxxyy");
	ft_necklace_test("xyxxz", "xxyxz");
	ft_necklace_test("x", "x");
	ft_necklace_test("x", "xx");
	ft_necklace_test("x", "");
	ft_necklace_test("", "");
	return (0);
}
