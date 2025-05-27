/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:56:29 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:19:02 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdio.h> // pour printf
#include <string.h> //pour strdup

void	test_strdup(void)
{
	printf("*********************************************************************************************************\n");
	printf("--------------------------------------------test STRDUP-------------------------------------------------\n");
	printf("CAS GENERAL\n");
	char	*s1 = "Hello World";
	char	*ft_dup1 = ft_strdup(s1);
	char	*sys_dup1 = strdup(s1);
	print_test_cmpr("TEXT-ft_strdup(\"Hello World\")", ft_dup1, sys_dup1);
	print_test_different_ptr("POINTER-ft_strdup(\"Hello World\")", ft_dup1, s1);
	free(ft_dup1);
	free(sys_dup1);

	printf("CAS-src = \"\"");
	char *s2 = "";
	char *ft_dup2 = ft_strdup(s2);
	char *sys_dup2 = strdup(s2);
	print_test_cmpr("TEXT-ft_strdup(\"\")", ft_dup2, sys_dup2);
	print_test_different_ptr("POINTER-ft_strdup(\"\")", ft_dup2, s2);
	free(ft_dup2);
	free(sys_dup2);

	printf("CAS-src = \"42\"");
	char *s3 = "42";
	char *ft_dup3 = ft_strdup(s3);
	char *sys_dup3 = strdup(s3);
	print_test_cmpr("TEXT-ft_strdup(\"42\")", ft_dup3, sys_dup3);
	print_test_different_ptr("POINTER-ft_strdup(\"42\")", ft_dup3, s3);
	free(ft_dup3);
	free(sys_dup3);

	printf("CAS-src = \"a\\0b\"");
	char *s4 = "a\\0b";
	char *ft_dup4 = ft_strdup(s4);
	char *sys_dup4 = strdup(s4);
	print_test_cmpr("TEXT-ft_strdup(\"a\\0b\")", ft_dup4, sys_dup4);
	print_test_different_ptr("POINTER-ft_strdup(\"a\\0b\")", ft_dup4, s4);
	free(ft_dup4);
	free(sys_dup4);
}