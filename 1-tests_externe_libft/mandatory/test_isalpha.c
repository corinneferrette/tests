/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 18:55:05 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h>// pour isalpha
#include <stdio.h>// pour printf


//sous linux il faut x1024
void	test_isalpha(void)
{
	printf("********************************************************************************************************-\n");
	printf("--------------------------------------------test ISALPHA-------------------------------------------------\n");
	printf("                             retourne des octets; soit 0 soit 1024 au lieu de 1                          \n");
	int os_val;
	#ifdef __linux__
		os_val = 1024;
	#elif __APPLE__
		os_val = 1;
	#elif _WIN32
		os_val = 1;
	#else
		os_val = 1;
	#endif
	print_test_int("ft_isalpha('a')", ft_isalpha('a'), isalpha('a')/ os_val);
	print_test_int("ft_isalpha('Z')", ft_isalpha('Z'), isalpha('Z')/ os_val);
	print_test_int("ft_isalpha('0')", ft_isalpha('0'), isalpha('0')/ os_val);
	print_test_int("ft_isalpha('\t')", ft_isalpha('\t'), isalpha('\t')/ os_val);
	print_test_int("ft_isalpha('@)", ft_isalpha('@'), isalpha('@')/ os_val);
	print_test_int("ft_isalpha((char)200)",
		       ft_isalpha((char)200), isalpha((char)200)/ os_val);
}
