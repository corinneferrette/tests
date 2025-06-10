/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:20:33 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:51:05 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
// #include <stddef.h>//pour size_t
// #include <string.h> //pour strnstr & NULL
#include <stdio.h>  // pour printf

void	test_strtrim(void)
{
	printf("*********************************************************************************************************\n");
	printf("---------------------------------------------test STRTRIM-----------------------------------------------\n");

	char *res = ft_strtrim(" 42 "," ");
	print_test_cmpr("ft_strtrim(\" 42 \", \" \")", res, "42");
	free(res);

	res = ft_strtrim("!!hello!!", "!");
	print_test_cmpr("ft_strtrim(\"!!hello!!\", \"!\")", res, "hello");
	free(res);

	res = ft_strtrim("abc", "abc");
	print_test_cmpr("ft_strtrim(\"abc\", \"abc\")", res, "");
	free(res);

	res = ft_strtrim("", " ");
	print_test_cmpr("ft_strtrim(\"\", \" \")", res, "");
	free(res);

	res = ft_strtrim("abc", "");
	print_test_cmpr("ft_strtrim(\"abc\", \"\")", res, "abc");
	free(res);

	res = ft_strtrim(NULL, " ");
	print_test_cmpr("ft_strtrim(NULL, \" \")", res, NULL);
	free(res);

	res = ft_strtrim("abc", NULL);
	print_test_cmpr("ft_strtrim(\"abc\", NULL)", res, NULL);
	free(res);

	res = ft_strtrim("hello", " ");
	print_test_cmpr("trim '  hello  ' avec ' '", res, "hello");
	free(res);

	res = ft_strtrim("abc", "abc");
	print_test_cmpr("trim 'abc' avec 'abc'", res, "");
	free(res);

	res = ft_strtrim("xyzabcxyz", "xyz");
	print_test_cmpr("trim 'xyzabcxyz' avec 'xyz'", res, "abc");
	free(res);

	res = ft_strtrim("hello", "");
	print_test_cmpr("trim 'hello' avec ''", res, "hello");
	free(res);

	res = ft_strtrim("", "abc");
	print_test_cmpr("trim '' avec 'abc'", res, "");
	free(res);

}
