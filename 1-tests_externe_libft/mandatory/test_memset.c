/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 11:27:13 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <string.h>// pour memset
#include <stdio.h>// pour printf

// CAS OU LE NBRE DE CARACTERE A MOFIFIER EST DE 0
// NE FONCTIONNE PAS A CAUSE DE error: 
// ‘memset’ used with constant zero length parameter; 
// this could be due to transposed parameters [-Werror=memset-transposed-args]

void	test_memset(void)
{
	char	generic1[6] = "COUCOU";
	char	specific1[6] = "COUCOU";
	char	generic2[5] = "SALUT";
	char	specific2[5] = "SALUT";
	char	generic3[5] = "SALUT";
	char	specific3[5] = "SALUT";

	printf("************************************************************************************************-\n");
	printf("-----------------------------------test MEMSET-----X = 88 ---------------------------------------\n");
	printf("REMPLACE LES 3 PREMIERS OCTECT PAR X\n");
	memset(generic1, 'X', 3);
	ft_memset(specific1, 'X', 3);
	print_test_int("ft_memset(COUCOU,'X', 3)-[0]", \
		specific1[0], generic1[0]);
	print_test_int("ft_memset(COUCOU,'X', 3)-[2]", \
		specific1[2], generic1[2]);
	print_test_int("ft_memset(COUCOU, 'X', 3)-[5]", \
		specific1[5], generic1[5]);
	printf("REMPLACE LES 3 PREMIERS OCTECT PAR -1\n");
	memset(generic2, -1, 3);
	ft_memset(specific2, -1, 3);
	print_test_int("ft_memset(SALUT,-1, 3)-[0]", \
		specific2[0], generic2[0]);
	print_test_int("ft_memset(SALUT,-1, 3)-[2]", \
		specific2[2], generic2[2]);
	print_test_int("ft_memset(SALUT, -1, 3)-[4]", \
		specific2[4], generic2[4]);
	printf("REMPLACE 0 OCTECTS\n");
	memset(generic3, 'X', (0));
	ft_memset(specific3, 'X', (0));
	print_test_int("ft_memset(\"SALUT\", 'X', 0)-[0]", \
		specific3[0], generic3[0]);
	print_test_int("ft_memset(\"SALUT\", 'X', 0)-[2]", \
		specific3[2], generic3[2]);
	print_test_int("ft_memset(\"SALUT\", 'X', 0)-[4]", \
		specific3[4], generic3[4]);
}
