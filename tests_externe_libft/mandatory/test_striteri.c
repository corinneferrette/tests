/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:33:16 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/22 11:21:10 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h>// pour isprint
#include <stdio.h>// pour printf
void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}


void test_striteri(void)
{
	printf("****************************************************************************************************-\n");
	printf("-------------------------------test STRITERI-----------------------------------------------------------\n");

	char str[100];
	ft_strlcpy(str, "hello", 6);
	ft_striteri(str, to_upper);
	print_test_cmpr("ft_striteri(\"hello\", to_upper)", str, "HELLO");

	ft_strlcpy(str, "", 1);
	ft_striteri(str, to_upper);
	print_test_cmpr("ft_striteri(\"\", to_upper)", str, "");

	ft_strlcpy(str,"test", 5);
	ft_striteri(str, NULL);
	print_test_cmpr("ft_striteri(\"test\", NULL)", str, str);

	ft_strlcpy(str, "42 @ Paris", 11);
	ft_striteri(str, to_upper);
	print_test_cmpr("ft_striteri(\"42 @ Paris\", to_upper)", str, "42 @ PARIS");
}
