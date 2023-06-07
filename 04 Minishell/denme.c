#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	child_initilaze(char **env)
{
	int id;
	int i;
	char **str;


	str = malloc(sizeof(char * ) * 3);
	str[0] = ft_strdup("/bin/ls");
	str[1] = ft_strdup("-la");
	str[2] = NULL;
	//id = fork();
	//wait(NULL);
	id = 4;
	if (id >= 1)
	{
		 i = execve(str[0], str, env);
		 printf(" i: %d\n", i);
	}
	else
		printf("main pid: %d\n", getpid());
		
		
}

int main (int ac, char **av, char **env)
{
  		child_initilaze(env);
}