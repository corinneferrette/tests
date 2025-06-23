/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:44 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/19 14:27:09 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_test.h"
#include <stdio.h>
#include <stddef.h>

void test_s(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%s ===\n");

	printf("Cas 1 : chaîne classique\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "Bonjour");
	ret2 = printf("printf    : [%s]\n", "Bonjour");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 2 : chaîne vide\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "");
	ret2 = printf("printf    : [%s]\n", "");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 3 : chaîne avec espaces\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "   ");
	ret2 = printf("printf    : [%s]\n", "   ");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 4 : chaîne NULL\n");
	ret1 = ft_printf("ft_printf : [%s]\n", (char *)NULL);
	ret2 = printf("printf    : [%s]\n", (char *)NULL);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 5 : chaîne avec caractères spéciaux\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "\tTab\nNewline");
	ret2 = printf("printf    : [%s]\n", "\tTab\nNewline");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 6 : longue chaîne\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "Une très longue chaîne pour tester si tout s'affiche correctement !");
	ret2 = printf("printf    : [%s]\n", "Une très longue chaîne pour tester si tout s'affiche correctement !");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 7 : chaîne abc\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "\1\2\3abc");
	ret2 = printf("printf    : [%s]\n", "\1\2\3abc");
	
	printf("\nFrancinette \"\"\n");
	ret1 = ft_printf("ft_printf : [%s]\n", "");
	ret2 = printf("printf    : [%s]\n", "");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("\nFrancinette \" \"\n");
	ret1 = ft_printf("ft_printf : [ %s]\n", "");
	ret2 = printf("printf    : [ %s]\n", "");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("\nFrancinette NULL\n");
	ret1 = ft_printf("ft_printf : NULL -> %s\n", (char *)NULL);
	ret2 = printf("printf    : NULL -> %s\n", (char *)NULL);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
