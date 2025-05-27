/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:44 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/27 18:10:53 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "print_test.h"
#include <stdio.h>

void test_s(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%s ===\n");

	// Cas 1 : chaîne classique
	ret1 = ft_printf("ft_printf : [%s]\n", "Bonjour");
	ret2 = printf("printf    : [%s]\n", "Bonjour");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 2 : chaîne vide
	ret1 = ft_printf("ft_printf : [%s]\n", "");
	ret2 = printf("printf    : [%s]\n", "");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 3 : chaîne avec espaces
	ret1 = ft_printf("ft_printf : [%s]\n", "   ");
	ret2 = printf("printf    : [%s]\n", "   ");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 4 : chaîne NULL
	ret1 = ft_printf("ft_printf : [%s]\n", (char *)NULL);
	ret2 = printf("printf    : [%s]\n", (char *)NULL);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 5 : chaîne avec caractères spéciaux
	ret1 = ft_printf("ft_printf : [%s]\n", "\tTab\nNewline");
	ret2 = printf("printf    : [%s]\n", "\tTab\nNewline");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 6 : longue chaîne
	ret1 = ft_printf("ft_printf : [%s]\n", "Une très longue chaîne pour tester si tout s'affiche correctement !");
	ret2 = printf("printf    : [%s]\n", "Une très longue chaîne pour tester si tout s'affiche correctement !");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 7 : chaîne avec caractères ASCII faibles
	ret1 = ft_printf("ft_printf : [%s]\n", "\1\2\3abc");
	ret2 = printf("printf    : [%s]\n", "\1\2\3abc");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
