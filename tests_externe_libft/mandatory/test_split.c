/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:08:47 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 19:13:20 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
// #include <stddef.h> // pour NULL
#include <string.h> // pour split
#include <stdio.h>  // pour printf

void	free_split(char **arr)
{
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	test_split(void)
{
	printf("************************************************************************************************-\n");
	printf("-----------------------------------test SPLIT------------------------------------------------\n");
	// Test 1 : Chaîne vide
	char *expected1[] = {NULL};
	char **res = ft_split("", ' ');
	compare_string_tab("ft_split(\"\", ' ')", res, expected1);
	free_split(res);

	// Test 2 : Chaîne contenant uniquement des espaces
	char *expected2[] = {NULL};
	res = ft_split("   ", ' ');
	compare_string_tab("ft_split(\"   \", ' ')", res, expected2);
	free_split(res);

	// Test 3 : Chaîne sans séparateur
	char *expected3[] = {"abc", NULL};
	res = ft_split("abc", ' ');
	compare_string_tab("ft_split(\"abc\", ' ')", res, expected3);
	free_split(res);

	// // Test 4 : Séparateur en début de chaîne
	// char *expected4[] = {"abc", NULL};
	// res = ft_split(" abc", ' ');
	// compare_string_tab("ft_split(\" abc\", ' ')", res, expected4);
	// free_split(res);

	// // Test 5 : Séparateur en fin de chaîne
	// char *expected5[] = {"abc", NULL};
	//res = ft_split("abc ", ' ');
	// compare_string_tab("ft_split(\"abc \", ' ')", , expected5);
	// free_split(res);

	// Test 6 : Séparateurs multiples entre les mots
	char *expected6[] = {"a", "b", "c", NULL};
	res = ft_split("a  b   c", ' ');
	compare_string_tab("ft_split(\"a  b   c\", ' ')", res, expected6);
	free_split(res);

	// // Test 7 : Séparateur unique entre les mots
	// char *expected7[] = {"a", "b", "c", NULL};
	//res = ft_split("a b c", ' ');
	// compare_string_tab("ft_split(\"a b c\", ' ')", res, expected7);
	// free_split(res);

	// Test 8 : Séparateur unique différent de l'espace
	char *expected8[] = {"a", "b", "c", NULL};
	res = ft_split("a,b,c", ',');
	compare_string_tab("ft_split(\"a,b,c\", ',')", res, expected8);
	free_split(res);

	// // Test 9 : Chaîne avec des caractères spéciaux
	// char *expected9[] = {"a", "b\nc", NULL};
	//res =ft_split("a\tb\nc", '\t');
	// compare_string_tab("ft_split(\"a\tb\nc\", '\t')", res, expected9);
	// free_split(res);

	// // Test 10 : Séparateur au début et à la fin
	// char *expected10[] = {"a", "b", "c", NULL};
	// res = ft_split(",a,b,c,", ',');
	// compare_string_tab("ft_split(\",a,b,c,\", ',')", res, expected10);
	// free_split(res);

	// Test 11 : Mots vides entre les séparateurs
	char *expected11[] = {"a", "b", "c", NULL};
	res = ft_split("a,,b,,,c", ',');
	compare_string_tab("ft_split(\"a,,b,,,c\", ',')", res, expected11);
	free_split(res);

	// Test 12 : Chaîne contenant uniquement le séparateur
	char *expected12[] = {NULL};
	res = ft_split(",", ',');
	compare_string_tab("ft_split(\",\", ',')", res, expected12);
	free_split(res);

	// Test 13 : Chaîne avec caractères non imprimables
	// char *expected13[] = {"a", "b", "c", NULL};
	// res = ft_split("a\0b\0c", '\0');
	// compare_string_tab("ft_split(\"a\\0b\\0c\", '\\0')", res, expected13);
	// free_split(res);

	// // Test 14 : Espaces multiples et tabulations
	// char *expected14[] = {"a ", " b ", " c", NULL};
	//res = ft_split("a \t b \t\t c", '\t');
	// compare_string_tab("ft_split(\"a \t b \t\t c\", '\t')", res expected14);
	// free_split(res);

	// // Test 15 : Caractères Unicode
	// char *expected15[] = {"éàè", "ç", "ô", NULL};
	// compare_string_tab("ft_split(\"éàè,ç,ô\", ',')", res, expected15);
	// free_split(res);

	// // Test 16 : Chiffres et lettres
	// char *expected16[] = {"123", "bc456def", NULL};
	// res = ft_split("éàè,ç,ô", ',');
	// compare_string_tab("ft_split(\"123abc456def\", 'a')", ft_split("123abc456def", 'a'), expected16);
	// free_split(res);

	// // Test 17 : Séparateurs consécutifs
	// char *expected17[] = {"a", "b", "c", NULL};
	// compare_string_tab("ft_split(\"a--b--c\", '-')", res, expected17);
	// free_split(res);

	// // Test 18 : Séparateurs mixtes
	// char *expected18[] = {"a", "b;c:d", NULL};
	// res = ft_split("a--b--c", '-');
	// compare_string_tab("ft_split(\"a,b;c:d\", ',')", ft_split("a,b;c:d", ','), expected18);
	// free_split(res);

	// // Test 19 : Espaces en début et fin
	// char *expected19[] = {"a", "b", "c", NULL};
	// compare_string_tab("ft_split(\"  a b c  \", ' ')", ft_split("  a b c  ", ' '), expected19);
	// free_split(res);

	// // Test 20 : Caractères spéciaux comme séparateur
	// char *expected20[] = {"a", "b", "c", NULL};
	// compare_string_tab("ft_split(\"a*b*c\", '*')", ft_split("a*b*c", '*'), expected20);
	// free_split(res);

}