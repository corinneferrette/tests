/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:35:47 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 18:27:00 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h" 
#include <string.h>
#include <stdio.h>

void	test_memchr(void)
{
	printf("**********************************************************************************************************-\n");
	printf("------------------------------------------test MEMCHR-----------------------------------------------------\n");
	printf("CAS GENERAL - c est dans str\n");
	char srcA[] = "Hello world";
	char *dest1 = ft_memchr(srcA, 'o', 11);
	char *dest2 = memchr(srcA,'o', 11);
	print_test_ptr("POINTER-ft_memchr(\"Hello world\", \'o\',11)", dest1, dest2);
	print_test_cmpr("TEXT-ft_memchr(\"Hello world\", \'o\',11)", dest1, dest2);


	printf("CAS GENERAL - c n'est pas dans str\n");
	char srcB[] = "Hello world";
	char *dest3 = ft_memchr(srcB, 'a', 11);
	char *dest4 = memchr(srcB, 'a', 11);
	print_test_ptr("POINTER-ft_memchr(\"Hello world\", \'a\',11)", dest3, dest4);
	print_test_cmpr("TEXT-ft_memchr(\"Hello world\", \'a\',11)", dest3, dest4);


	printf("CAS - str est vide\n");// si on met plus que 0 en size on a un probleme de valgring car on essaye de lire a un endroit aui na pas ete iunitalise
	char srcC[] = "";
	char *dest5 = ft_memchr(srcC, 'a', 0);
	char *dest6 = memchr(srcC, 'a', 0);
	print_test_ptr("POINTER-ft_memchr(\"\", \'a\',11)", dest5, dest6);
	print_test_cmpr("TEXT-ft_memchr(\"\", \'a\',11)", dest5, dest6);

	
	printf("CAS - c = '\\0'\n");
	char srcD[] = "a\0b";
	char *dest7 = ft_memchr(srcD, '\0', 11);
	char *dest8 = memchr(srcD, '\0', 11);
	print_test_ptr("POINTER-ft_memchr(\"A\\0\", \'\\0\',11)", dest7, dest8);
	print_test_cmpr("TEXT-ft_memchr(\"A\\0\", \'\\0\',11)", dest7, dest8);


	printf("CAS GENERAL - c est dans str mais pas l'octet\n");
	char srcE[] = "Hello world";
	char *dest9 = ft_memchr(srcE, 'w', 4);
	char *dest10 = memchr(srcE, 'w', 4);
	print_test_ptr("POINTER-ft_memchr(\"Hello world\", \'o\',11)", dest9, dest10);
	print_test_cmpr("TEXT-ft_memchr(\"Hello world\", \'o\',11)", dest9, dest10);

}
