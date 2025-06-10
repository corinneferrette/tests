/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:08:17 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 10:55:35 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdio.h>// pour printf

//STRNSTR N EXISTE PAS SOUS LINUX IL FAUR DONC COMPARER AU RESULTAT ATTENDU ET NON AU RESULTAT DE LA FONCTION

void	test_strnstr(void)
{
	char	*res;
    	char	*exp;
	printf("*********************************************************************************************************\n");
	printf("---------------------------------------------test STRNSTR------------------------------------------------\n");
	printf("STRNSTR-CAS STANDARD\n");
	res = ft_strnstr("Hello world", "world", 11);
	exp = "world";
	print_test_cmpr("ft_strnstr(\"Hello world\", \"world\", 11)", res, exp);
	printf("STRNSTR-AUCUNE CORRESPONDANCE TROUVEE\n");
	res = ft_strnstr("abcdef", "xyz", 6);
	exp = NULL;
	print_test_cmpr("ft_strnstr(\"abcdef\", \"xyz\", 6)", res, exp);	
	printf("STRNSTR-CORRESPONDANCE AU DELA DE LA LONGUEUR DE LA CHAINE\n");
	res = ft_strnstr("abcdef", "def", 3);
	exp = NULL;	
	print_test_cmpr("ft_strnstr(\"abcdef\", \"def\", 3)",  res, exp);
	printf("STRNSTR-CORRESPONDANCE PARTIELLEMENT AU DELA DE LA LONGUEUR DE LA CHAINE\n");
	res = ft_strnstr("Hello world", "world", 5);
	exp = NULL;
	print_test_cmpr("ft_strnstr(\"Hello world\", \"world\", 5)",  res, exp);
	printf("STRNSTR-CORRESPONDANCE VIDE\n");
	res = ft_strnstr("abc", "", 3);
	exp = "abc";	
	print_test_cmpr("ft_strnstr(\"abc\", \"\", 3)",  res, exp);
	printf("STRNSTR-CHAINE DE RECHERCHE VIDE\n");
	res = ft_strnstr("", "a", 1);
    	exp = NULL;
	print_test_cmpr("ft_strnstr(\"\",\"a)\", 1", res, exp);
	printf("STRNSTR-LEN = 0\n");
	res = ft_strnstr("abc", "a", 0);
    	exp = NULL;	
	print_test_cmpr("ft_strnstr(\"abc\", \"a\", 0)",  res, exp);
}
