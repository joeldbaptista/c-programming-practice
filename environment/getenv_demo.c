#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *shell = getenv("SHELL");
	printf("The current shell is: %s\n", shell);
	return 0;
}
