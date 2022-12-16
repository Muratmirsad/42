#include "get_next_line.h"
int main()
{
	int fd = open("gnlTester/files/empty", O_RDWR);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


}