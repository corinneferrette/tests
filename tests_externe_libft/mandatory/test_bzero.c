/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 10:53:50 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <string.h>//  pour bzero
#include <stdio.h>// pour printf


void	test_bzero(void)
{
	char	generic0[] = "COUCOU";//pas possible de faire autrement pour aue ce soit modofiable
	char	specific0[] = "COUCOU";
	// char	generic1[] = "COUCOU"; pas testable
	char	specific1[] = "COUCOU";
	char	generic2[] = "";
	char	specific2[] = "";

	printf("********************************************************************************************************-\n");
	printf("------------------------------------------------test BZERO-----------------------------------------------\n");
	printf("--------------------------------------------------N < LEN------------------------------------------------\n");
	ft_bzero(specific0, 3);
	bzero(generic0, 3);
	print_test_int("ft_bzero(\"COUCOU\",3)-[0]", specific0[0], generic0[0]);
	print_test_int("ft_bzero\"COUCOU\",3)-[2]", specific0[2], generic0[2]);
	print_test_int("ft_bzero(\"COUCOU\",3)-[3]", specific0[3], generic0[3]);
	printf("--------------------------------------------------N = 0-------------------------------------------------\n");
	ft_bzero(specific1, (0));
	// bzero(generic1, 0); PAS TESTABLE
	print_test_int("ft_bzero(COUCOU,3)-[0]", specific1[0], 'C');
	print_test_int("ft_bzero(COUCOU,3)-[2]", specific1[2], 'U');
	print_test_int("ft_bzero(COUCOU,3)-[3]", specific1[3], 'C');
	printf("-----------------------------------------------STR EST VIDE----------------------------------------------\n");
	ft_bzero(specific2, 1);
	bzero(generic2, 1);
	print_test_int("ft_bzero(COUCOU,3)-[0]", specific2[0], generic2[0]);
	// print_test_int("ft_bzero(COUCOU,3)-[2]", specific2[2], generic2[2]);
	// print_test_int("ft_bzero(COUCOU,3)-[3]", specific2[3], generic2[3]);
}
