/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:53:03 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/21 13:48:07 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define RED "\x1b[0;31m"
#define GRN "\x1b[0;32m"
#define RESET "\x1b[0m"

static int	total_tests = 0;
static int	passed_tests = 0;

// void	print_test_simple(char *test_n, int res)
// {
// 	if (res == 1)
// 		printf(GRN"%s: OK\n"RESET, test_n);
// 	else
// 		printf(RED"%s: KO\n"RESET, test_n);
// }

// void	print_int_test(char *test_n, int res, int val, int(*f)(int))

// {
// 	if (res == 1)
// 		printf(GRN"%s ----> %d : OK\n"RESET, test_n, f(val));
// 	else
// 		printf(RED"%s ----> %d : ko\n"RESET, test_n, f(val));
// }

// void	print_char_test(char *test_n, int res, char *str, int(*f)(char*))

// {
// 	if (res == 1)
// 		printf(GRN"%s ----> %d : OK\n"RESET, test_n, f(str));
// 	else
// 		printf(RED"%s ----> %d : ko\n"RESET, test_n, f(str));
// }

void print_bytes(const char *test_n, const unsigned char *ptr, size_t len)
{
	printf("%s (%zu octets) : ", test_n, len);
	for (size_t i = 0; i < len; i++)
		printf("%02x ", ptr[i]); // affiche chaque octet en hexadécimal
	printf("\n");
}

void	print_test_int(char *test_n, int res, int exp)
{
	total_tests++;
	// if (!exp)
	// 	exp = NULL;
	// if (!RESET)
	// 	res = NULL;
	if (res == exp)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: %-15d | Expected: %d\n" RESET, test_n, res,  exp);
	}
	else
		printf(RED "%-40s: KO \
			Result: %-15d | Expected: %d\n" RESET, test_n, res,  exp);
}

void	print_test_str(char *test_n, char *res, char *exp)
{
	total_tests++;
	char *res_orig = res;
	char *exp_orig = exp;
	// Si l'un des deux résultats est NULL, vérifie que l'autre l'est aussi
	if (res == NULL && exp == NULL)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET, test_n, res_orig, exp_orig);
		return;
	}
	// Si un des deux résultats est NULL, le test échoue
	else if (res == NULL || exp == NULL)
	{
		printf(RED "%-40s: KO \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET, test_n, res, exp);
		return;
	}

	// Compare les chaînes de manière classique
	while (*res && *exp && (*res == *exp))
	{
		res++;
		exp++;
	}

	// Vérifie si on a atteint la fin des deux chaînes
	if (*res == '\0' && *exp == '\0')
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: \"%s\"\t\t| Expectedc: \"%s\"\n" RESET, test_n, res_orig, exp_orig);
	}
	else
	{
		printf(RED "%-40s: KO \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET, test_n,res, exp);
	}

}

void	print_test_cmpr(char *test_n, char *res, char *exp)
{
	total_tests++;
	if (res == NULL && exp == NULL)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET,
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
		return ;
	}
	if (res == NULL || exp == NULL)
	{
		printf(RED "%-40s: KO \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET,
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
		return;
	}
	if (strcmp(res, exp) == 0)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET,
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
	}
	else
		printf(RED "%-40s: KO \
			Result: \"%s\"\t\t| Expected: \"%s\"\n" RESET, \
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
}

void print_test_cmprn(char *test_n, char *res, char *exp)
{
	total_tests++;
	if (res == NULL && exp == NULL)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: %-18s \t| Expected: %s\n" RESET, \
			test_n, res ? res : "(null)", exp ? exp : "(null)");
		return;
	}
	if (res == NULL || exp == NULL)
	{
		printf(RED "%-40s: KO \
	 		Result: %-18s \t| Expected: %s\n" RESET,
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
		return;
	}
	
	if (strcmp(res, exp) == 0)
	{
		passed_tests++;

		printf(GRN "%-40s: OK \
			Result: %-18s \t| Expected: %s\n" RESET,
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
	}
	else
		printf(RED "%-40s: KO \
			Result: %-18s \t| Expected: %s\n" RESET,
		       test_n, res ? res : "(null)", exp ? exp : "(null)");
}

void print_test_ptr(char *test_n, char *res, char *exp)
{
	total_tests++;
	// if (!exp)
	// 	exp = NULL;
	// if (!RESET)
	// 	res = NULL;
	if (res == exp)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			Result: %-15p  | Expected: %p\n" RESET,
		       test_n, res, exp);
	}
	else
		printf(RED "%-40s: KO \
			Result: %-15p  | Expected: %p\n" RESET,
		       test_n, res, exp);
}

void print_test_different_ptr(char *test_n, char *res, char *exp)
{
	total_tests++;
	// if (!exp)
	// 	exp = NULL;
	// if (!RESET)
	// 	res = NULL;
	if (res != exp)
	{
		passed_tests++;
		printf(GRN "%-40s: OK \
			(ft_Result: %-15p  | src_adress: %p\n" RESET,
		       test_n, res, exp);
	}
	else
		printf(RED "%-40s: KO \
			(ft_Result: %-15p  | src_adress: %p\n" RESET,
		       test_n, res, exp);
}

void print_test_calloc(const char *test_n, size_t count, size_t size)
{
	void *exp = calloc(count, size);
	void *res = ft_calloc(count, size);

	if (!exp && !res)
		printf(GRN "%-40s: OK \
		Result: \"(null)\"\t| Expected: \"(null)\"\n" RESET,
		       test_n);
	else if (exp && res && memcmp(exp, res, count * size) == 0)
	{
		printf(GRN "%-40s: OK \
		Result: %zu X 0\t| Expected: %zu X 0\n" RESET,
			test_n, count, count);
	}
	else if ((count == 0 ||size == 0) && exp && res)
	{
		printf(GRN "%-40s: OK \
		Result: \'(non null)\"\t| Expected:'(non null)\"\n" RESET,
			test_n);
	}
	else
		printf("KO - %s\n", test_n);
	free(exp);
	free(res);
}

// void print_test_memcpy(const char *test_n, const void *src, size_t len)
// {
// 	unsigned char dest1[100] = {0}; // destination pour ft_memcpy
// 	unsigned char dest2[100] = {0}; // destination pour memcpy

// 	ft_memcpy(dest1, src, len);
// 	memcpy(dest2, src, len);
// 	if (memcmp(dest1, dest2, len) == 0)
// 	{
// 		passed_tests++;
// 		// printf(GRN "%-40s: OK Result: %-18s \t| Expected: %s\n" RESET, test_n, print_bytes("-",dest1, len), len);
// 		printf("✅ %s OK pour %zu octets\n", test_n, len);
// 	}
// 	else
// 	{
// 		printf("❌ ft_memcpy KO pour %zu octets\n", len);
// 		printf("dest1 :");
// 		for (size_t i = 0; i < len; i++)
// 			printf(" %02x", dest1[i]);
// 		printf("\n");

// 		printf("dest2 :");
// 		for (size_t i = 0; i < len; i++)
// 			printf(" %02x", dest2[i]);
// 		printf("\n");
// 	}
// }

// Pour test_split
// static int count_tab(char **tab)
// {
// 	int i = 0;
// 	while (tab && tab[i])
// 		i++;
// 	return (i);
// }

// void compare_string_tab(const char *test_n, char **result, char **expected)
// {
// 	int i = 0;
// 	if (!result && !expected)
// 	{
// 		printf(GRN "%-40s: OK (Length: 0)     Result: (null)     | Expected: (null)\n" RESET, test_n);
// 		return;
// 	}
// 	else if (!result || !expected)
// 	{
// 		printf(RED "%-40s: KO                 Result: %s | Expected: %s\n" RESET,
// 		       test_n,
// 		       result ? "non-null" : "(null)",
// 		       expected ? "non-null" : "(null)");
// 		return;
// 	}

// 	while (result[i] && expected[i])
// 	{
// 		if (strcmp(result[i], expected[i]) != 0)
// 		{
// 			printf(RED "%-40s: KO (Mismatch at [%d]: \"%s\" vs \"%s\")\n" RESET,
// 			       test_n, i, result[i], expected[i]);
// 			return;
// 		}
// 		i++;
// 	}
// 	if (result[i] != NULL || expected[i] != NULL)
// 	{
// 		printf(RED "%-40s: KO (Different lengths: result=%d, expected=%d)\n" RESET,
// 		       test_n, count_tab(result), count_tab(expected));
// 		return;
// 	}
// 	printf(GRN "%-30s: OK (Length: %d)     Result: {", test_n, i);
// 	if (result)

// 	{
// 		for (int j = 0; j < i; j++)
// 		{
// 			printf("\"%s\"", result[j]);
// 			if (j < i - 1)
// 				printf(", ");
// 		}
// 	}
// 	else
// 		printf("(null)");
// 	printf("} \t\t| Expected: {");
// 	if (expected)
// 	{
// 		for (int j = 0; j < i; j++)
// 		{
// 			printf("\"%s\"", expected[j]);
// 			if (j < i - 1)
// 				printf(", ");
// 		}
// 	}
// 	else
// 		printf("(null)");
// 	printf("}\n" RESET);
// }


void compare_string_tab(const char *test_n, char **result, char **expected)
{
	int i = 0;

	// Cas où les deux tableaux sont NULL
	if (!result && !expected)
	{
		printf(GRN "%-40s: OK (Length: 0)     Result: (null)     | Expected: (null)\n" RESET, test_n);
		return;
	}
	// Cas où l'un des deux tableaux est NULL
	else if (!result || !expected)
	{
		printf(RED "%-40s: KO                 Result: %s | Expected: %s\n" RESET,
		       test_n,
		       result ? "non-null" : "(null)",
		       expected ? "non-null" : "(null)");
		return;
	}

	// Comparaison des éléments des deux tableaux
	while (result[i] && expected[i])
	{
		if (strcmp(result[i], expected[i]) != 0)
		{
			// Affichage en cas de différence
			printf(RED "%-40s: KO at [%d]          Result: {", test_n, i);
			for (int j = 0; result[j]; j++)
			{
				printf("\"%s\"", result[j]);
				if (result[j + 1])
					printf(", ");
			}
			printf("} | Expected: {");
			for (int j = 0; expected[j]; j++)
			{
				printf("\"%s\"", expected[j]);
				if (expected[j + 1])
					printf(", ");
			}
			printf("}\n" RESET);
			return;
		}
		i++;
	}

	// Vérification de la longueur des tableaux
	if (result[i] || expected[i])
	{
		printf(RED "%-40s: KO (different lengths) Result: {", test_n);
		for (int j = 0; result[j]; j++)
		{
			printf("\"%s\"", result[j]);
			if (result[j + 1])
				printf(", ");
		}
		printf("} | Expected: {");
		for (int j = 0; expected[j]; j++)
		{
			printf("\"%s\"", expected[j]);
			if (expected[j + 1])
				printf(", ");
		}
		printf("}\n" RESET);
		return;
	}

	// Affichage en cas de succès
	printf(GRN "%-40s: OK (Length: %d)     Result: {", test_n, i);
	for (int j = 0; j < i; j++)
	{
		printf("\"%s\"", result[j]);
		if (j < i - 1)
			printf(", ");
	}
	printf("} | Expected: {");
	for (int j = 0; j < i; j++)
	{
		printf("\"%s\"", expected[j]);
		if (j < i - 1)
			printf(", ");
	}
	printf("}\n" RESET);
}

// void run_test_safely(void (*test_func)(void), const char *label)
// {
// 	pid_t pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		return;
// 	}
// 	if (pid == 0)
// 	{
// 		// Fils : exécute le test
// 		test_func();
// 		exit(EXIT_SUCCESS); // pas de segfault
// 	}
// 	else
// 	{
// 		int status;
// 		waitpid(pid, &status, 0);
// 		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
// 			printf("❌ %s : SEGFAULT détecté\n", label);
// 		else if (WIFEXITED(status))
// 			printf("✅ %s : OK (exit %d\n", label, WEXITSTATUS(status));
// 		else
// 			printf("⚠️  %s : autre erreur\n", label);
// 	}
// }

void print_final_result(void)
{
	printf("=== RESULTATS FINAUX ===\n");
	if (passed_tests == total_tests)
		printf(GRN "%d/%d tests passed\n" RESET, passed_tests, total_tests);
	else
		printf(RED "%d/%d tests passed\n" RESET, passed_tests, total_tests);
}
