#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	envp[0][0] = '\0';
	printf("%s\n", envp[0]);
	if (!envp[0][0])
		printf("%d\n", 0);
}
