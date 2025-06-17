/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:07 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/11 16:27:51 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_test.h"
#include <stdio.h>
#include <limits.h> // pour UINT_MAX

void	test_x_X(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%x et %%X ===\n");

	printf("Cas 1 : zéro\n");
	ret1 = ft_printf("ft_printf : [%x]\n", 0);
	ret2 = printf("printf    : [%x]\n", 0);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 2 : valeur simple 42\n");
	ret1 = ft_printf("ft_printf : [%x]\n", 42);
	ret2 = printf("printf    : [%x]\n", 42);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 3 : valeur avec lettres hex 255\n");
	ret1 = ft_printf("ft_printf : [%x]\n", 255); // FF
	ret2 = printf("printf    : [%x]\n", 255);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 4 : grande valeur 3735928559u\n");
	ret1 = ft_printf("ft_printf : [%x]\n", 3735928559u); // deadbeef
	ret2 = printf("printf    : [%x]\n", 3735928559u);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 5 : UINT_MAX\n");
	ret1 = ft_printf("ft_printf : [%x]\n", UINT_MAX);
	ret2 = printf("printf    : [%x]\n", UINT_MAX);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 6 : %%X avec même valeur 3735928559u\n");
	ret1 = ft_printf("ft_printf : [%X]\n", 3735928559u); // DEADBEEF
	ret2 = printf("printf    : [%X]\n", 3735928559u);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 7 : %%X avec zéro\n");
	ret1 = ft_printf("ft_printf : [%X]\n", 0);
	ret2 = printf("printf    : [%X]\n", 0);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
