/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:00:45 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/21 13:39:40 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <string.h> // pour memcmp
#include <stdio.h> // pour printf

char	*cmp_result_str(int val)
{
	if (val == 0)
		return "EGAUX";
	else if (val > 0)
		return ">0";
	else
		return "<0";
}

void	test_memcmp(void)
{
	printf("*************************************************************************************************\n");
	printf("------------------test MEMCMP----ATTENTION SUR MAC M4 LES RESULTATS SONT OPTIMISES---------------\n");
	

	

	print_test_str("ft_memcmp(\"abc\", \"abc\", 3)",
		cmp_result_str(ft_memcmp("abc", "abc", 3)),
		cmp_result_str(memcmp("abc", "abc", 3)));

	print_test_str("ft_memcmp(\"abc\", \"abf\", 1)",
		cmp_result_str(ft_memcmp("abc", "abf", 1)),
		cmp_result_str(memcmp("abc", "abf", 1)));

	print_test_str("ft_memcmp(\"abd\", \"abc\", 1)",
		cmp_result_str(ft_memcmp("abd", "abc", 1)),
		cmp_result_str(memcmp("abd", "abc", 1)));

	print_test_str("ft_memcmp(\"abc\", \"abc\", 0)",
		cmp_result_str(ft_memcmp("abc", "abc", 0)),
		cmp_result_str(memcmp("abc", "abc", 0)));

	print_test_str("ft_memcmp(\"abc\", \"abg\", 3)",
		cmp_result_str(ft_memcmp("abc", "abg", 3)),
		cmp_result_str(memcmp("abc", "abg", 3)));

	char *test4 = "a\200";
	char *test41 = "a\0";
	print_test_str("ft_memcmp(\"a\\200\", \"a\\0\", 2)",
		cmp_result_str(ft_memcmp(test4, test41, 2)),
		cmp_result_str(memcmp(test4, test41, 2)));

	char *test5 = "\x0f\xaa\xde\xffMACOSX\xff";
	char *test51 = "\x0f\xaa\xde\x02";
	print_test_str("ft_memcmp(\"\\x0f\\xaa\\xde\\xffMACOSX\\xff\", \"\\x0f\\xaa\\xde\\x02\", 8)",
		cmp_result_str(ft_memcmp(test5, test51, 8)),
		cmp_result_str(memcmp(test5, test51, 8)));

	char *test6 = "\xff\xaa\xde\xffMACOSX\xff";
	char *test61 = "\xff\xaa\xde\x02";
	print_test_str("ft_memcmp(\"\\xff\\xaa\\xde\\xffMACOSX\\xff\", \"\\xff\\xaa\\xde\\x02\", 10)",
		cmp_result_str(ft_memcmp(test6, test61, 10)),
		cmp_result_str(memcmp(test6, test61, 10)));

}