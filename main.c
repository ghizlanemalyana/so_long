#include <stdio.h>
# include <errno.h>
# include <string.h>

int main(int ac, char **av)
{
	printf("%s\n", strerror(errno));
}
