/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 10:56:20 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h>// pour tolower
#include <stdio.h>// pour printf

void	test_tolower(void)
{
	printf("********************************************************************************************************-\n");
	printf("-------------------------------------------test TOLOWER--------------------------------------------------\n");
	print_test_int("ft_tolower('a')", ft_tolower('a'), tolower('a'));
	print_test_int("ft_tolower('Z')", ft_tolower('Z'), tolower('Z'));
	print_test_int("ft_tolower('0')", ft_tolower('0'), tolower('0'));
	print_test_int("ft_tolower('\t')", ft_tolower('\t'), tolower('\t'));
	print_test_int("ft_tolower('@')", ft_tolower('@'), tolower('@'));
	print_test_int("ft_tolower((char)127)", \
		ft_tolower((char)127), tolower((char)127));
}
