/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:56:06 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/17 16:17:51 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include "print_test.h"
#include <stddef.h> //  pour bzero
#include <stdio.h>
#include <string.h> //pour NULL
#include <ctype.h>
#include <stdlib.h>

void	test_c(void);
void	test_s(void);
void	test_d_i(void);
void	test_p(void);
void	test_u(void);
void	test_x_X(void);
void	test_percent(void);

int	main(void)
{
	printf("-------------------- TEST FT_PRINTF RAPIDE-----------------\n");
	int	count_ft = 0;
	int	count_sys = 0;

	// Test %c (caractère)
	count_ft = ft_printf("1. Char: %c\n", 'A');
	count_sys = printf("1. Char: %c\n", 'A');
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %s (chaîne)
	count_ft = ft_printf("2. String: %s\n", "Hello, 42!");
	count_sys = printf("2. String: %s\n", "Hello, 42!");
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %d et %i (entiers signés)
	count_ft = ft_printf("3. Int (%%d): %d | Int (%%i): %i\n", 42, -42);
	count_sys = printf("3. Int (%%d): %d | Int (%%i): %i\n", 42, -42);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %u (entier non signé)
	count_ft = ft_printf("4. Unsigned: %u\n", 3000000000u);
	count_sys = printf("4. Unsigned: %u\n", 3000000000u);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %x et %X (hexadécimal)
	count_ft = ft_printf("5. Hex minuscule: %x | Hex MAJ: %X\n", 255, 255);
	count_sys = printf("5. Hex minuscule: %x | Hex MAJ: %X\n", 255, 255);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %p (pointeur)
	int x = 42;
	count_ft = ft_printf("6. Pointer: %p\n", &x);
	count_sys = printf("6. Pointer: %p\n", &x);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);


	printf("-------------------- TEST FT_PRINTF COMPLET------------------\n");
	test_c();
	test_s();
	test_d_i();
	test_p();
	test_u();
	test_x_X();
	test_percent();

	printf("-------------------- TEST PERSONNALISE------------------\n");
	ft_printf("VOICI MON TEST PERSONNALISE %d%c%s%p\n", 42, 5, "bonjour", "pointeur");

	return (0);
}
