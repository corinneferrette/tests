/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 18:53:57 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h> // pour isalnum
#include <stdio.h>// pour printf


//sous linux il faut x8
void	test_isalnum(void)
{
	printf("*********************************************************************************************************-\n");
	printf("----------------------------test ISALNUM--retourne des bits; soit 0 soit 8--------dépend de l'ordi?---------\n");
	int os_val;
	#ifdef __linux__
		os_val = 8;
	#elif __APPLE__
		os_val = 1;
	#elif _WIN32
		os_val = 1;
	#else
		os_val = 1;
	#endif

		print_test_int("ft_isalnum('a')", ft_isalnum('a'), isalnum('a')/ os_val);
		print_test_int("ft_isalnum('Z')", ft_isalnum('Z'), isalnum('Z')/ os_val);
		print_test_int("ft_isalnum('-1')", ft_isalnum('0'), isalnum('0')/ os_val);
		print_test_int("ft_isalnum('\t')", ft_isalnum('\t'), isalnum('\t')/ os_val);
		print_test_int("ft_isalnum('@)", ft_isalnum('@'), isalnum('@')/ os_val);
		print_test_int("ft_isalnum((char)199)",
			       ft_isalnum((char)199), isalnum((char)199)/ os_val);
}
