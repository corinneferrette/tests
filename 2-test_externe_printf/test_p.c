/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:06 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/28 17:52:38 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_test.h"
#include <stdio.h>

void test_p(void)
{
	int ret1, ret2;
	int x = 42;
	int *ptr = &x;
	void *null_ptr = NULL;

	printf("\n=== TEST %%p ===\n");

	printf("Cas 1 : pointeur sur une variable\n");
	ret1 = ft_printf("ft_printf : [%p]\n", ptr);
	ret2 = printf("printf    : [%p]\n", ptr);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 2 : pointeur NULL\n");
	ret1 = ft_printf("ft_printf : [%p]\n", null_ptr);
	ret2 = printf("printf    : [%p]\n", null_ptr);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 3 : pointeur vers une string\n");
	char *s = "hello";
	ret1 = ft_printf("ft_printf : [%p]\n", s);
	ret2 = printf("printf    : [%p]\n", s);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 4 : pointeur vers une fonction\n");
	void (*fptr)(void) = test_p;
	ret1 = ft_printf("ft_printf : [%p]\n", fptr);
	ret2 = printf("printf    : [%p]\n", fptr);
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
