/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:05:11 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 19:10:26 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h> // pour memset
#include <stdlib.h> // pour calloc
#include "libft.h"
#include "../print_test.h"

void test_calloc(void)
{
	printf("**********************************************************************************************************-\n");
	printf("------------------------------------------test CALLOC-----------------------------------------------------\n");
	// int *exp = calloc(5, sizeof(int));
	// int *res = ft_calloc(5, sizeof(int));
	print_test_calloc("ft_calloc(5, sizeof(int))", 5, sizeof(int));


	//On ne peut pas lire ptr[0] si on a fait calloc(0, x) ou calloc(x, 0) ou calloc(0, 0)
	//On peut juste Vérifier que le pointeur n’est pas NULL
	// ft_calloc(0,0) doit retrouner un pointeur non NULL
	// int *exp1 = calloc(0, 0);
	// int *res1 = ft_calloc(0, 0);
	print_test_calloc("ft_calloc(0, 0) doit retourner un \n \tpointeur non nul sur mon mac que l'on peut free", 0, 0);
;
	// ft_calloc(1,0) doit retrouner un pointeur non NULL
	// int *exp2 = calloc(1, 0);
	// int *res2 = ft_calloc(1, 0);
	print_test_calloc("ft_calloc(1, 0) doit retourner un \n \tpointeur non nul sur mon mac que l'on peut free", 1, 02);

	// ft_calloc(0,1) doit retrouner un pointeur non NULL
	// int *exp3 = calloc(0, 1);
	// int *res3 = ft_calloc(0, 1);
	print_test_calloc("ft_calloc(1, 0) doit retourner un \n \tpointeur non nul sur mon mac que l'on peut free", 0, 1);
	
	// // ft_calloc(1000000,1000000) doit retrouner un pointeur non NULL
	// int *exp4 = calloc(1000000, 1000000);
	// int *res4 = ft_calloc(1000000, 1000000);
	// print_test_calloc("ft_calloc(1000000, 1000000) doit retourner un \n \tpointeur non nul sur mon mac que l'on peut free", res3[0], exp3[0]);

}
