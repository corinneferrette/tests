/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:04:38 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/20 09:53:32 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdio.h>// pour printf

//ITOA N EXISTE PAS  - IL FAUT COMPARER AU RESULTAT ATTNDU
void	test_itoa(void)
{
	printf("*****************************************************************************************************\n");
	printf("--------------------------------------------test ITOA------------------------------------------------\n");
	char*res = ft_itoa(42);
	print_test_cmpr("ft_itoa(42)", res, "42\0");
	free(res);

	res = ft_itoa(-42);
	print_test_cmpr("ft_itoa(-42)", res, "-42");
	free(res);

	res = ft_itoa(0);
	print_test_cmpr("ft_itoa(0)", res, "0");
	free(res);

	res = ft_itoa(2147483647);
	print_test_cmpr("ft_itoa(2147483647)", res, "2147483647");
	free(res);

	res = ft_itoa(-2147483647);
	print_test_cmpr("ft_itoa(-2147483647)", res, "-2147483647");
	free(res);

}
