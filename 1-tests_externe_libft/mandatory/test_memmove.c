/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:55:22 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 11:26:56 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // pour printf
#include <string.h> // pour memmove
#include "libft.h"
#include "../print_test.h"

void	print_memory(const void *mem, size_t len)
{
    const unsigned char *p = mem;
    for (size_t i = 0; i < len; ++i)
        printf("%02x ", p[i]);
    printf("\n");
}

void	test_memmove(void)
{
	char ft_test[20] = "abcdefghij";
	char sys_test[20] = "abcdefghij";

	printf("*********************************************************************************************************\n");
	printf("--------------------------------------------test MEMMOVE-------------------------------------------------\n");
	printf("CHEVAUCHEMENT VERS LA DROITE\n");
	ft_memmove(ft_test + 2,ft_test, 5);
	memmove(sys_test + 2, sys_test, 5);
	print_test_cmpr("ft_memmove(str + 2, str = \"abcdefghij\", 5)", ft_test, sys_test);

	printf("CHEVAUCHEMENT VERS LA GAUCHE\n");
	strcpy(ft_test, "abcdefghij");
	strcpy(sys_test, "abcdefghij");
	ft_memmove(ft_test, ft_test + 2, 5);
	memmove(sys_test, sys_test + 2, 5);
	print_test_cmpr("ft_memmove(str = \"abcdefghij\", str + 2, 5)", ft_test, sys_test);

	printf("SRC == DST\n");
	strcpy(ft_test, "abcdefghij");
	strcpy(sys_test, "abcdefghij");
	ft_memmove(ft_test, ft_test, 5);
	memmove(sys_test, sys_test, 5);
	print_test_cmpr("ft_memmove(str = \"abcdefghij\", str + 0, 5)", ft_test, sys_test);

	printf("LEN == 0\n");
	strcpy(ft_test, "abcdefghij");
	strcpy(sys_test, "abcdefghij");
	ft_memmove(ft_test, ft_test, 0);
	memmove(sys_test, sys_test, 0);
	print_test_cmpr("ft_memmove(str = \"abcdefghij\", str + 0, 0)", ft_test, sys_test);

	printf("DST == NULL && SRC == NULL\n");
	strcpy(ft_test, "");
	strcpy(sys_test, "");
	ft_memmove(ft_test, ft_test, 5);
	memmove(sys_test, sys_test, 5);
	print_test_cmpr("ft_memmove(DST = \"\", SRC = \"\", 5)", ft_test, sys_test);

	printf("TEST s1=NULL ET s2=NULL ET LEN = 0\n");
	char *str1 = NULL;
	char *str2 = NULL;
	print_test_cmpr("ft_memmove(NULL, NULL, 0)",
			ft_memmove(str1, str1, 0),
			memmove(str2, str2, 0));

	// // test NULL avec len > 0 (doit planter ou retourner NULL)
	// printf("TEST s1=NULL ET s2=NULL ET LEN > 0\n");
	// strcpy(ft_test, NULL);
	// strcpy(sys_test, NULL);
	// print_test_cmpr("ft_memmove(NULL, NULL, 2)",
	// 		    ft_memmove(ft_test, ft_test, 2),
	// 		    memmove(sys_test, sys_test, 2));

	// // test NULL avec len > 0 (doit planter ou retourner NULL)
	// printf("TEST  s2=NULL ET LEN > 0\n");
	// strcpy(ft_test, "abcdefghij");
	// strcpy(sys_test, "abcdefghij");
	// print_test_cmpr("ft_memmove (\"abcdefg\", NULL, 2)",
	// 		ft_memmove(ft_test, NULL, 2),
	// 		memmove(sys_test, NULL, 2));
	// printf("TEST s1=NULL ET LEN > 0\n");
	// strcpy(ft_test, "abcdefghij");
	// strcpy(sys_test, "abcdefghij");
	// print_test_cmpr("ft_memmove (NULL, \"abcdefghij\", 2)",
	// 		ft_memmove(NULL, ft_test, 2),
	// 		memmove(NULL, sys_test, 2));
}	    
