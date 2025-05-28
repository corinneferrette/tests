/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 10:54:37 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdio.h>// pour printf
#include <ctype.h>// pour isascii


void	test_isascii(void)
{
	printf("*********************************************************************************************************\n");
	printf("------------------------------test ISASCII---------------------------------------------------------------\n");
	print_test_int("ft_isascii('a')", ft_isascii('a'), isascii('a'));
	print_test_int("ft_isascii('Z')", ft_isascii('Z'), isascii('Z'));
	print_test_int("ft_isascii(0)", ft_isascii(0), isascii(0));
	print_test_int("ft_isascii('\t')", ft_isascii('\t'), isascii('\t'));
	print_test_int("ft_isascii('@)", ft_isascii('@'), isascii('@'));
	print_test_int("ft_isascii((char)200)", \
		ft_isascii((char)200), isascii((char)200));
}
