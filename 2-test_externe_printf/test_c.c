/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:55:56 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/19 14:26:14 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "print_test.h"
#include <stdio.h>
#include <stddef.h>

void test_c(void)
{
	int ret1, ret2;

	printf("\n=== TEST %%c ===\n");

	printf("lettre majuscule\n");
	ret1 = ft_printf("ft_printf : [%c]\n", 'B');
	ret2 = printf("printf    : [%c]\n", 'B');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("caractère spécial\n");
	ret1 = ft_printf("ft_printf : [%c]\n", '@');
	ret2 = printf("printf    : [%c]\n", '@');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("caractère numérique (codé comme caractère)\n");
	ret1 = ft_printf("ft_printf : [%c]\n", '5');
	ret2 = printf("printf    : [%c]\n", '5');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("caractère nul (\\0)\n");
	ret1 = ft_printf("ft_printf : [\\0 = %c]\n", '\0');
	ret2 = printf("printf    : [\\0 = %c]\n", '\0');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("caractère TAB ('\t' = tabulation)\n");
	ret1 = ft_printf("ft_printf : [%c]\n", '\t');
	ret2 = printf("printf    : [%c]\n", '\t');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("caractère DEL (DEL = 127)\n");
	ret1 = ft_printf("ft_printf : [%c]\n", 127);
	ret2 = printf("printf    : [%c]\n", 127);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("valeur hors plage signée (-42)\n");
	ret1 = ft_printf("ft_printf : [%c]\n", -42);
	ret2 = printf("printf    : [%c]\n", -42);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("valeur hors plage standard (200)\n");
	ret1 = ft_printf("ft_printf : [%c]\n", 200);
	ret2 = printf("printf    : [%c]\n", 200);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Francinette '0'\n");
	ret1 = ft_printf("ft_printf : [%c]\n", '0');
	ret2 = printf("printf    : [%c]\n", '0');
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Francinette '0' - 256\n");
	ret1 = ft_printf("ft_printf : [%c]\n", '0' - 256);
	ret2 = printf("printf    : [%c]\n", '0' - 256);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}

// int	main(void)
// {
// 	test_c();
// 	return (0);
// }