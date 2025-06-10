/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:59:17 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 11:27:24 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdio.h>
#include <string.h>// pour strchr

void	test_strchr(void)
{
	printf("************************************************************************************************-\n");
	printf("-----------------------------------test STRCHR-1ERE OCCURENCE------------------------------------\n");

	print_test_str("ft_strchr(\"hello\", 'e')", \
			ft_strchr("hello", 'e'), strchr("hello", 'e')); // "ello"
	print_test_str("ft_strchr(\"hello\", 'l')", \
		       	ft_strchr("hello", 'l'), strchr("hello", 'l')); // "llo"
	print_test_str("ft_strchr(\"hello\", 'z')", \
			ft_strchr("hello", 'z'), strchr("hello", 'z')); // NULL
	print_test_str("ft_strchr(\"hello\", '\\0')",
		       ft_strchr("hello", '\0'), strchr("hello", '\0')); // ""
	print_test_str("ft_strchr(\"\", '\\0')", \
			ft_strchr("", '\0'), strchr("", '\0')); // ""
}
