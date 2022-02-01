#include "ft_printf.c"
#include <stdio.h>

int main()
{
	printf(" len = %i", ft_printf("%10.5s", NULL));
	printf("\n");
	printf(" len = %i", printf("%10.5s", NULL));
}
