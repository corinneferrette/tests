/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:03:47 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/27 18:10:58 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "print_test.h"
#include <stdio.h>
#include <limits.h>  // pour INT_MAX, INT_MIN

void test_d_i(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%d et %%i ===\n");

	// Cas 1 : zéro
	ret1 = ft_printf("ft_printf : [%d]\n", 0);
	ret2 = printf("printf    : [%d]\n", 0);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 2 : entier positif
	ret1 = ft_printf("ft_printf : [%d]\n", 12345);
	ret2 = printf("printf    : [%d]\n", 12345);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 3 : entier négatif
	ret1 = ft_printf("ft_printf : [%d]\n", -12345);
	ret2 = printf("printf    : [%d]\n", -12345);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 4 : INT_MAX
	ret1 = ft_printf("ft_printf : [%d]\n", INT_MAX);
	ret2 = printf("printf    : [%d]\n", INT_MAX);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 5 : INT_MIN
	ret1 = ft_printf("ft_printf : [%d]\n", INT_MIN);
	ret2 = printf("printf    : [%d]\n", INT_MIN);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 6 : avec %i au lieu de %d
	ret1 = ft_printf("ft_printf : [%i]\n", 42);
	ret2 = printf("printf    : [%i]\n", 42);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 7 : entier négatif avec %i
	ret1 = ft_printf("ft_printf : [%i]\n", -999);
	ret2 = printf("printf    : [%i]\n", -999);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
