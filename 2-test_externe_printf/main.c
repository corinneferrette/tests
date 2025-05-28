/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:56:06 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/28 17:51:54 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include "print_test.h"
#include <stddef.h> //  pour bzero
#include <stdio.h>
#include <string.h> //pour NULL
#include <ctype.h>
#include <stdlib.h>

void	test_c(void);
void	test_s(void);
void	test_d_i(void);
void	test_p(void);
void	test_u(void);
void	test_x_X(void);
void	test_percent(void);

int	main(void)
{
	printf("-------------------- TEST FT_PRINTF --------xxx----------\n");
	test_c();
	test_s();
	test_d_i();
	test_p();
	test_u();
	test_x_X();
	test_percent();
	return (0);
}
