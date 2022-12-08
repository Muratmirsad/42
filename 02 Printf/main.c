# include "ft_printf.h"

int main()
{
	char *str = "test";
	//long	n = 999;

	printf("\n%d\n", ft_printf("\nu '87263323':%u\nu '-87263323':%u\nd '-87263323':%d\n", 87263323, -87263323, -87263323));
	printf("\n%d\n", printf("\nu '87263323':%u\nu '-87263323':%u\nd '-87263323':%d\n", 87263323, -87263323, -87263323));

	//printf("%d\n---\n", ft_printf("%d\n", 100));
	//printf("%d\n", printf("%d\n", 100));


	/*ft_printf("FT_PRINTF\nX: %X\nx: %x\nx: %x\nd: %d\nd: %d\nu: %u\nu: %u\n",123, 123, -123, 123, -123, 123, -123);
	printf("\nORGINAL\nX: %X\nx: %x\nx: %x\nd: %d\nd: %d\nu: %u\nu: %u\n",123, 123, -123, 123, -123, 123, -123);

	ft_printf("\n\n------------------\n\n");

	ft_printf("FT_PRINTF\n%%%%%%%%");
	printf("ORGINAL\n%%%%%%%%\n");*/

	//printf("%d\n", ft_printf("FT_PRINTF\n\n%s%s <---\n", str, str));
	//printf("%d\n", printf("->ORGINAL\n\n%s%s <---\n", str, str));
	//printf("\n%s\n", str);

	//ft_printf("FT_PRINTF\n%p <---", str);
	//printf("ORGINAL\n%p <---\n", str);
	//printf("ORGINAL\np: %p\n", str);

	return (0);
}