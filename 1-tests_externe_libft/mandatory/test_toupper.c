/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 10:56:28 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h>// pour toupper
#include <stdio.h>// pour printf

void	test_toupper(void)
{
	printf("********************************************************************************************************-\n");
	printf("---------------------------------------test TOUPPER------------------------------------------------------\n");
	print_test_int("ft_toupper('a')", ft_toupper('a'), toupper('a'));
	print_test_int("ft_toupper('Z')", ft_toupper('Z'), toupper('Z'));
	print_test_int("ft_toupper('0')", ft_toupper('0'), toupper('0'));
	print_test_int("ft_toupper('\t')", ft_toupper('\t'), toupper('\t'));
	print_test_int("ft_toupper('@')", ft_toupper('@'), toupper('@'));
	print_test_int("ft_toupper((char)127)", \
		ft_toupper((char)127), toupper((char)127));
}
