/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:54:16 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:45:17 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h" 
// substr n'existe pas en c
#include <string.h>
// #include <unistd.h> // pour size_t
// #include <string.h> // pour strlcpy
#include <stdio.h>// pour printf

void	test_substr(void)
{
	printf("**********************************************************************************************************-\n");
	printf("------------------------------------------test SUBSTR-----------------------------------------------------\n");
	
	char	*res = ft_substr("abcdef", 2, 3);
	print_test_cmpr("ft_substr(\"abcdef\", 1, 3)", res, "cde");
	free(res);

	res = ft_substr("abcdef", 0, 3);
	print_test_cmpr("ft_substr(\"abcdef\", 0, 3)", res, "abc");
	free(res);

	res = ft_substr("", 1, 3);
	print_test_cmpr("ft_substr(\"\", 1, 3)", res, "");
	free(res);

	res = ft_substr("abcdef", 4, 10);
	print_test_cmpr("ft_substr(\"abcdef\", 4, 10)", res, "ef");
	free(res);

	res = ft_substr(NULL, 0, 1);
	print_test_cmpr("ft_substr(NULL, 1, 3)", res, NULL);
	free(res);
}
