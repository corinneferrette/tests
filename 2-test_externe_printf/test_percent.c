/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:59:40 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/28 17:52:44 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_test.h"
#include <stdio.h>

void test_percent(void)
{
	int ret1, ret2;

	printf("\n=== TEST %% (double pourcentage) ===\n");

	printf("Cas 1 : afficher un pourcentage seul\n");
	ret1 = ft_printf("ft_printf : [%%]\n");
	ret2 = printf("printf    : [%%]\n");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 2 : pourcentage dans une phrase\n");
	ret1 = ft_printf("ft_printf : 100%% sûr\n");
	ret2 = printf("printf    : 100%% sûr\n");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);

	printf("Cas 3 : plusieurs pourcentages\n");
	ret1 = ft_printf("ft_printf : %% %% %%\n");
	ret2 = printf("printf    : %% %% %%\n");
	printf("→ retour ft_printf : %d | printf : %d\n\n", ret1, ret2);
}
