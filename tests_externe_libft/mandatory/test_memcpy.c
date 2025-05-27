/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:09:15 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/21 13:49:06 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stddef.h> // pour NULL
#include <string.h> // pour memcpy
#include <stdio.h>  // pour printf

void test_memcpy(void)
{
	printf("*************************************************************************************************\n");
	printf("-----------------------------------------test MEMCPY---------------------------------------------\n");
	printf("--------------------Attention pour comparer un \\0 a été ajouté sur dest[len]--------------------\n");
	printf("CAS GENERAL\n");
	char srcA[] = "Hello World";
	char	dest1[20];
	char	dest2[20];
	ft_memcpy(dest1, srcA, 5);
	memcpy(dest2, srcA, 5);
	dest1[5] = '\0';// mis là plutot que dans le print pour éviter les problèmes
	dest2[5] = '\0';
	print_test_cmprn("ft_memcpy(dest, \"Hello world\", 5)", dest1, dest2, 5);

	printf("CAS GENERAL2\n");
	char srcA1[] = "Hello World";
	char destA1[20];
	char destA2[20];
	ft_memcpy(destA1, srcA1, 15);
	memcpy(destA2, srcA1, 15);
	dest1[15] = '\0'; // mis là plutot que dans le print pour éviter les problèmes
	dest2[15] = '\0';
	print_test_cmprn("ft_memcpy(dest, \"Hello world\", 12)", destA1, destA2, 15);

	printf("COPIER 0 OCTETS\n");
	char srcB[] = "Hello World";
	char dest3[20] = "Bonjour";
	char dest4[20] ="Bonjour";
	ft_memcpy(dest3, srcB, 0);
	memcpy(dest4, srcB, 0);
	print_test_cmprn("ft_memcpy(dest, \"Hello world\", 0)", dest3, dest4, 0);

	// printf("FAIT UN SEGFAULT\n");
	// printf("ft_memcpy(\"               \", ((void *)0))), 17)\n");
	// char *srcC = ((void *)0);
	// char dest5[20] = "                   ";
	// char dest6[20] = "                   ";
	// ft_memcpy(dest5, srcC, 17);
	// memcpy(dest6, srcC, 17);
	// run_test_safely(ft_memcpy(dest5, srcC, 17));

	printf("dest = NULL, src = NULL et len = 0\n");
	char *dest_ft = ft_memcpy(NULL, NULL, 0);
	// char *dest_sys = memcpy(NULL, NULL, 0);
	print_test_cmprn("ft_memcpy(dest = NULL, src = NULL, 0)", dest_ft, NULL, 0);
	
	printf("dest = NULL et len = 0\n");
	char srcD[] = "Hello World";
	char *dest7 = NULL;
	char *dest8 = NULL;
	ft_memcpy(dest7, srcD, 0);
	memcpy(dest8, srcD, 0);
	print_test_cmprn("ft_memcpy(dest = NULL, \"Hello World\", 0)", dest7, dest8, 0);

	printf("src = NULL et len = 0\n");
	char *srcF = NULL;
	char dest11[20] = "Bonjour";
	char dest12[20]= "Bonjour";
	ft_memcpy(dest11, srcF, 0);
	memcpy(dest12, srcF, 0);
	print_test_cmprn("ft_memcpy(\"Bonjour\", NULL, 0)", dest7, dest8, 0);

	// printf("src = NULL, dest = NULL et len >0\n");
	// // char *srcE = NULL;
	// // void *dest9 = NULL;
	// void *dest10 = NULL;
	// // ft_memcpy(((void *)0), ((void *)0), 3);//Segmentation Fault
	// memcpy(((void *)0), dest10, 3);
	// print_bytes("ft_memcpy(((void *)0), ((void *)0), 3)", dest10, 3);
	// print_test_cmprn("ft_memcpy(((void *)0), ((void *)0), 3)", dest9, dest10, 0);

	// // Test with binary data
	// unsigned char bin_src[] = {0x00, 0xFF, 0x42, 0x10};
	// unsigned char bin_dest1[4], bin_dest2[4];
	// memcpy(bin_dest1, bin_src, 4);
	// ft_memcpy(bin_dest2, bin_src, 4);
	// print_test_memcmp("ft_memcpy binary data",
	// 		  bin_dest1, bin_dest2, 4);
}
