#include "libftprintf.h"
#include "libft/libft.h"

#include <stdio.h>

int main(void)
{
	int	count_ft = 0;
	int	count_sys = 0;

	// Test %c (caractère)
	count_ft = ft_printf("1. Char: %c\n", 'A');
	count_sys = printf("1. Char: %c\n", 'A');
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %s (chaîne)
	count_ft = ft_printf("2. String: %s\n", "Hello, 42!");
	count_sys = printf("2. String: %s\n", "Hello, 42!");
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %d et %i (entiers signés)
	count_ft = ft_printf("3. Int (%%d): %d | Int (%%i): %i\n", 42, -42);
	count_sys = printf("3. Int (%%d): %d | Int (%%i): %i\n", 42, -42);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %u (entier non signé)
	count_ft = ft_printf("4. Unsigned: %u\n", 3000000000u);
	count_sys = printf("4. Unsigned: %u\n", 3000000000u);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %x et %X (hexadécimal)
	count_ft = ft_printf("5. Hex minuscule: %x | Hex MAJ: %X\n", 255, 255);
	count_sys = printf("5. Hex minuscule: %x | Hex MAJ: %X\n", 255, 255);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %p (pointeur)
	int x = 42;
	count_ft = ft_printf("6. Pointer: %p\n", &x);
	count_sys = printf("6. Pointer: %p\n", &x);
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	// Test %%
	count_ft = ft_printf("7. Pourcentage: %%\n");
	count_sys = printf("7. Pourcentage: %%\n");
	printf("→ %d caractères imprimés-%d ok\n\n", count_ft, count_sys);

	return 0;
}