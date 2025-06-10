/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:13:08 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/28 17:53:03 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_test.h"
#include <stdio.h>
#include <limits.h> //pour UINT_MAX

void test_u(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%u ===\n");

	printf("Cas 1 : 0\n");
	ret1 = ft_printf("ft_printf : [%u]\n", 0);
	ret2 = printf("printf    : [%u]\n", 0);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 2 : petit entier\n");
	ret1 = ft_printf("ft_printf : [%u]\n", 42);
	ret2 = printf("printf    : [%u]\n", 42);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 3 : grand entier\n");
	ret1 = ft_printf("ft_printf : [%u]\n", 4000000000U);
	ret2 = printf("printf    : [%u]\n", 4000000000U);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 4 : UINT_MAX\n");
	ret1 = ft_printf("ft_printf : [%u]\n", UINT_MAX);
	ret2 = printf("printf    : [%u]\n", UINT_MAX);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 5 : valeur négative castée en unsigned\n");
	ret1 = ft_printf("ft_printf : [%u]\n", (unsigned int)-1);
	ret2 = printf("printf    : [%u]\n", (unsigned int)-1);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 6 : UINT_MAX\n");
	ret1 = ft_printf("ft_printf : [%u]\n", UINT_MAX);
	ret2 = printf("printf    : [%u]\n", UINT_MAX);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
