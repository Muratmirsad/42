# include "libftprintf.h"

int main()
{
	char *str = "test";
	long	n = 999;

	//ft_printf("u '87263323':%u\nu '-87263323':%u\nd '-87263323':%d\n", 87263323, -87263323, -87263323);
	//printf("\nu '87263323':%u\nu '-87263323':%u\nd '-87263323':%d\n", 87263323, -87263323, -87263323);


	ft_printf("x: %x\nx: %x\nd: %d\nd: %d\nu: %u\nu: %u\n", 123, -123, 123, -123, 123, -123);
	printf("\nORGINAL\nx: %x\nx: %x\nd: %d\nd: %d\nu: %u\nu: %u\n", 123, -123, 123, -123, 123, -123);

	return (0);
}