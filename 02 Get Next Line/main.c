#include "get_next_line.h"

int main(int av, char **ar)
{
	int	fd;

	printf("File: %d\n", fd = open("gnlTester/files/42_no_nl", O_RDONLY));
	printf("%s", get_next_line(fd));
	//printf("PART 2\n%s\n", get_next_line(fd));

	close(fd);

	return(0);
}