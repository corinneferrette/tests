/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:55:56 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/27 17:49:31 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"
#include "print_test.h"
#include <stdio.h>

void test_c(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%c ===\n");

	// Cas 1 : lettre majuscule
	ret1 = ft_printf("ft_printf : [%c]\n", 'A');
	ret2 = printf("printf    : [%c]\n", 'A');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 2 : caractère spécial
	ret1 = ft_printf("ft_printf : [%c]\n", '@');
	ret2 = printf("printf    : [%c]\n", '@');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 3 : caractère numérique (codé comme caractère)
	ret1 = ft_printf("ft_printf : [%c]\n", '5');
	ret2 = printf("printf    : [%c]\n", '5');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 4 : caractère nul (\0)
	ret1 = ft_printf("ft_printf : [\\0 = %c]\n", '\0');
	ret2 = printf("printf    : [\\0 = %c]\n", '\0');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 5 : caractère ASCII bas ('\t' = tabulation)
	ret1 = ft_printf("ft_printf : [%c]\n", '\t');
	ret2 = printf("printf    : [%c]\n", '\t');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 6 : caractère ASCII haut (DEL = 127)
	ret1 = ft_printf("ft_printf : [%c]\n", 127);
	ret2 = printf("printf    : [%c]\n", 127);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 7 : valeur hors plage signée (-42)
	ret1 = ft_printf("ft_printf : [%c]\n", -42);
	ret2 = printf("printf    : [%c]\n", -42);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	// Cas 8 : valeur hors plage standard (200)
	ret1 = ft_printf("ft_printf : [%c]\n", 200);
	ret2 = printf("printf    : [%c]\n", 200);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}

// int	main(void)
// {
// 	test_c();
// 	return (0);
// }