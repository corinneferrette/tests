/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:20:31 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/20 10:56:45 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <string.h> // pour strlen
#include <stdio.h>  // pour printf

int mac_safe_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int res = ft_strncmp(s1, s2, n);

#ifdef __APPLE__
	if (res < 0)
		return -1;
	else if (res > 0)
		return 1;
	else
		return 0;
#else
	return res;
#endif
}
void	test_strncmp(void)
{
	printf("*********************************************************************************************************\n");
	printf("--------------------------------------------test STRNCMP------------------------------------------------\n");

	// Test 1 : Chaînes identiques, n < longueur
	print_test_int("ft_strncmp(\"hello\", \"hello\", 3)", mac_safe_ft_strncmp("hello", "hello", 3), strncmp("hello", "hello", 3));

	// // Test 2 : Chaînes identiques, n > longueur
	print_test_int("ft_strncmp(\"hello\", \"hello\", 10)", mac_safe_ft_strncmp("hello", "hello", 10), strncmp("hello", "hello", 10));

	// // Test 3 : Chaîne 1 < Chaîne 2
	print_test_int("ft_strncmp(\"apple\", \"banana\", 5)", mac_safe_ft_strncmp("apple", "banana", 5), strncmp("apple", "banana", 5));

	// // Test 4 : Chaîne 1 > Chaîne 2
	print_test_int("ft_strncmp(\"orange\", \"grape\", 6)", mac_safe_ft_strncmp("orange", "grape", 6), strncmp("orange", "grape", 6));

	// // Test 5 : Préfixe commun, n < préfixe
	print_test_int("ft_strncmp(\"hello\", \"hell\", 3)", mac_safe_ft_strncmp("hello", "hell", 3), strncmp("hello", "hell", 3));

	// // Test 6 : Préfixe commun, n > préfixe
	print_test_int("ft_strncmp(\"hello\", \"hell\", 5)", mac_safe_ft_strncmp("hello", "hell", 5), strncmp("hello", "hell", 5));

	// // Test 7 : Chaînes vides, n = 0
	print_test_int("ft_strncmp(\"\", \"\", 0)", mac_safe_ft_strncmp("", "", 0), strncmp("", "", 0));

	// // Test 8 : Chaîne vide vs non vide, n > 0
	print_test_int("ft_strncmp(\"\", \"non-vide\", 1)", mac_safe_ft_strncmp("", "non-vide", 1), strncmp("", "non-vide", 1));

	// // Test 9 : Non vide vs chaîne vide, n > 0
	print_test_int("ft_strncmp(\"non-vide\", \"\", 1)", mac_safe_ft_strncmp("non-vide", "", 1), strncmp("non-vide", "", 1));

	// // Test 10 : Caractères spéciaux
	// print_test_int("ft_strncmp(\"hello!\", \"hello?\", 6)", mac_safe_ft_strncmp("hello!", "hello?", 6), strncmp("hello!", "hello?", 6));

	// // Test 11 : Nombres
	print_test_int("ft_strncmp(\"123\", \"1234\", 3)", mac_safe_ft_strncmp("123", "1234", 3), strncmp("123.", "1234", 3));

	// // Test 12 : Sensibilité à la casse
	// print_test_int("ft_strncmp(\"Hello\", \"hello\", 5)", mac_safe_ft_strncmp("Hello", "hello", 5), strncmp("Hello", "hello", 5));

	// // Test 13 : Caractères Unicode (en supposant un encodage compatible)
	print_test_int("ft_strncmp(\"éclair\", \"école\", 2)", mac_safe_ft_strncmp("éclair", "école", 2), strncmp("éclair", "école", 2));
}