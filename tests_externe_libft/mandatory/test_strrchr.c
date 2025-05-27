/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:04:12 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 18:08:20 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <string.h>// pour strrchr
#include <stdio.h>// pour printf



char *electric_alloc(size_t size)
{
	char *mem = malloc(size);
	if (mem)
		memset(mem, 0xAA, size); // remplissage pour détecter d’éventuelles erreurs
	return mem;
}

void	test_strrchr(void)
{
	printf("**********************************************************************************************************-\n");
	printf("------------------------------------------test STRRCHR-----------------------------------------------------\n");
	printf("CAS GENERAL\n");
	char *test1 = "bonjour";
	int i = 0;
	while (i <= 7)
	{
		if (test1[i] == '\0')
			printf("Lettre: \'\\0' - Pointeur: %p\n", &test1[i]);
		else
			printf("Lettre:    %c - Pointeur: %p\n", test1[i], &test1[i]);
		i++;
	}
	print_test_str("TXT-ft_strrchr(\"bonjour\",'o')",
		       ft_strrchr(test1, 'o'), strrchr(test1, 'o'));
	print_test_ptr("PTR-ft_strrchr(\"bonjour\",'o')", \
		ft_strrchr(test1, 'o'), strrchr(test1, 'o'));

	printf("RECHERCHE DE \'\\0\'\n");
	char *test2 = "bonjour";
	print_test_str("TXT-ft_strrchr(\"bonjour\",'\\0')",
		       ft_strrchr(test2, '\0'), strrchr(test2, '\0'));
	print_test_ptr("PTR-ft_strrchr(\"bonjour\",'\\0')",
			   ft_strrchr(test2, '\0'), strrchr(test2, '\0'));

	printf("RECHERCHE DE CARACTERE INEXISTANT\n");
	char *test3 = "bonjour";
	print_test_str("TXT-ft_strrchr(\"bonjour\",'c')",
		       ft_strrchr(test3, 'c'), strrchr(test3, 'c'));
	print_test_ptr("PTR-ft_strrchr(\"bonjour\",'c')",
			   ft_strrchr(test3, 'c'), strrchr(test3, 'c'));

	printf("TEST DE CARACTERE INEXISTANT AVEC ELECTRIC_ALLOC\n");
	char *test4 = electric_alloc(10);
	strcpy(test4, "123456789");
	print_test_str("TXT-ft_strrchr(\"123456789\",'a')",
					   ft_strrchr(test4, 'a'), strrchr(test4, 'a'));
	print_test_ptr("PTR-ft_strrchr(\"123456789\",'a')",
		       ft_strrchr(test4, 'a'), strrchr(test4, 'a'));
	free(test4);

	printf("2IEME TEST DE CARACTERE INEXISTANT AVEC ELECTRIC_ALLOC\n");
	char *test41 = electric_alloc(10);
	strcpy(test41, "123456789");
	print_test_str("TXT-ft_strrchr(\"123456789\",'a')",
		       ft_strrchr(test41, 'a'), strrchr(test41, 'a'));
	print_test_ptr("PTR-ft_strrchr(\"123456789\",'c')",
		       ft_strrchr(test41, 'a'), strrchr(test41, 'a'));
	free(test41);

	printf("RECHERCHE DE CARACTERE EN 1ERE PLACE\n");
	char *test5 = "bonjour";
	print_test_str("TXT-ft_strrchr(\"bonjour\",'b')",
			ft_strrchr(test5, 'b'), strrchr(test5, 'b'));
	print_test_ptr("PTR-ft_strrchr(\"bonjour\",'b')",
			ft_strrchr(test5, 'b'), strrchr(test5, 'b'));

	printf("RECHERCHE DANS UNE CHAINE VIDE\n");
	char *test6 = "";
	print_test_str("TXT-ft_strrchr(\"\",'c')",
		       ft_strrchr(test6, 'c'), strrchr(test6, 'c'));
	print_test_ptr("PTR-ft_strrchr(\"\",'c')",
		       ft_strrchr(test6, 'c'), strrchr(test6, 'c'));

       printf("RECHERCHE DE \'\\0\' DANS UNE CHAINE VIDE\n");
	char *test61 = "";
	print_test_str("TXT-ft_strrchr(\"\",\'\\0\')",
		       ft_strrchr(test61, '\0'), strrchr(test61, '\0'));
	print_test_ptr("PTR-ft_strrchr(\"\",'c')",
		       ft_strrchr(test61, '\0'), strrchr(test61, '\0'));

	printf("RECHERCHE DANS UNE CHAINE IDENTIQUE\n");
	char *test7 = "BBBBBBB";
	print_test_str("TXT-ft_strrchr(\"BBBBBBB\",'B')",
		       ft_strrchr(test7, 'B'), strrchr(test7, 'B'));
	print_test_ptr("PTR-ft_strrchr(\"\",'B')",
		       ft_strrchr(test7, 'B'), strrchr(test7, 'B'));

	printf("RECHERCHE DANS UNE CHAINE CONTENANT UN \\0\n");
	char *test8 = "b\0njour";
	print_test_str("TXT-ft_strrchr(\"b\\0njour\",'n')",
		       ft_strrchr(test8, 'n'), strrchr(test8, 'n'));
	print_test_ptr("PTR-ft_strrchr(\"\",'n')",
		       ft_strrchr(test8, 'n'), strrchr(test8, 'n'));

	printf("RECHERCHE DANS UNE CHAINE D UN INT\n");
	char *test9 = "bonjour";
	i = 0;
	while (i <= 7)
	{
		if (test1[i] == '\0')
			printf("Lettre: \'\\0' - Pointeur: %p\n", &test1[i]);
		else
			printf("Lettre:    %c - Pointeur: %p\n", test1[i], &test1[i]);
		i++;
	}
	print_test_str("TXT-ft_strrchr(\"bonjour\",1024)",
		       ft_strrchr(test9, 1024), strrchr(test9, 1024));
	print_test_ptr("PTR-ft_strrchr(\"bonjour\",1024)",
		       ft_strrchr(test9, 1024), strrchr(test9, 1024));
}

