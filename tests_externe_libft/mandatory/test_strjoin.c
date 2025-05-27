/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:07:25 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:26:50 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdio.h>  // pour printf
#include <stdlib.h> //pour strjoin

	void	test_strjoin(void)
{
	char *res;

	printf("*************************************************************************************************\n");
	printf("-----------------------------------------test STRJOIN--------------------------------------------\n");

	res = ft_strjoin("abc", "def");
	print_test_cmpr("ft_strjoin(\"abc\", \"def\")", res, "abcdef");
	free(res);

	res = ft_strjoin("", "abc");
	print_test_cmpr("ft_strjoin(\"\", \"abc\")", res, "abc");
	free(res);

	res = ft_strjoin("abc", "");
	print_test_cmpr("ft_strjoin(\"abc\", \"\")", res, "abc");
	free(res);

	res = ft_strjoin("", "");
	print_test_cmpr("ft_strjoin(\"\", \"\")", res, "");
	free(res);

	res = ft_strjoin(NULL, "abc");
	print_test_cmpr("ft_strjoin(NULL, \"abc\")", res, NULL);
	free(res);  // free(NULL) est safe

	res = ft_strjoin("abc", NULL);
	print_test_cmpr("ft_strjoin(\"abc\", NULL)", res, NULL);
	free(res);
}
	
