#include "main.h"

int	my_exit2(char **com)
{
  if (!com[1])
    {
      my_printf("exit\n");
      exit(0);
    }
  if (com[1] && com[2])
    {
      my_pute("exit: Expression Syntax.\n");
      return (1);
    }
  return (0);
}

char	**my_exit(char **com, char **env)
{
  int	i;
  int	j;

  i = 0;
  if (my_exit2(com) == 1)
    return (env);
  while (com[++i])
    {
      j = 0;
      while (com[i][j])
	{
	  if (com[i][j] != '-' && (com[i][j] < '0' || com[i][j] > '9'))
	    {
	      my_pute("exit: Expression Syntax.\n");
	      return (env);
	    }
	  j++;
	}
    }
  my_printf("exit\n");
  exit(my_getnbr(com[1]));
}

char	**search_built_in(char **com, char **env)
{
  if (my_strcmp(com[0], "exit"))
    return (my_exit(com, env));
  if (my_strcmp(com[0], "cd"))
    {
      my_cd(com, env);
      return (env);
    }
  if (my_strcmp(com[0], "setenv"))
    {
      env = my_setenv(com, env);
      return (env);
    }
  if (my_strcmp(com[0], "unsetenv"))
    {
      env = my_unsetenv(com, env);
      return (env);
    }
  if (my_strcmp(com[0], "pwd"))
    {
      my_printf("%s\n", getcwd(NULL, 0));
      return (env);
    }
  return (NULL);
}
