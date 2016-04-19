#include "main.h"

t_pip	separate_pipe1(t_pip pip, int *j, int i, char **com)
{
  int	k;

  k = 0;
  while (com[*j] && com[*j][0] != '|')
    {
      if ((pip.com[i][k] = malloc(my_strlen(com[*j]) + 1)) == NULL)
	exit(2);
      pip.com[i][k] = my_strcpy(pip.com[i][k], com[(*j)++]);
      k++;
    }
  pip.com[i][k] = NULL;
  if (com[*j])
    (*j)++;
  return (pip);
}

t_pip	separate_pipe(char **com, t_pip pip)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((pip.com = malloc(sizeof(char **) * pip.nbcom)) == NULL)
    exit(2);
  while (i < pip.nbcom)
    {
      if ((pip.com[i] = malloc(sizeof(char *) * count_l(com, j))) == NULL)
      	exit(2);
      pip = separate_pipe1(pip, &j, i, com);
      i++;
    }
  pip.com[i] = NULL;
  return (pip);
}

char	*ret_total(t_shell sh, char *com)
{
  int	i;
  int	m;
  char	*tmp;

  i = 0;
  m = 0;
  while (sh.path[i] && m == 0)
    {
      tmp = my_strcat(sh.path[i], com);
      if (access(tmp, F_OK) != -1 && access(tmp, X_OK) != -1)
        m = 1;
      if (m == 0)
	free(tmp);
      i++;
    }
  if (m == 1)
    return (tmp);
  return (NULL);
}

void	my_pipe2(char *com1, char *com2, t_pip pip, char **env)
{
  int	m;

  m = 0;
  if (com1 == NULL)
    {
      my_pute(pip.com[0][0]);
      my_pute(": Command not found.\n");
      m = 1;
    }
  if (com2 == NULL && m == 0)
    {
      my_pute(pip.com[0][0]);
      my_pute(": write error: Broken pipe\n");
    }
  else if (com2 == NULL && m == 1)
    {
      my_pute(pip.com[1][0]);
      my_pute(": Command not found.\n");
    }
  else if (m == 1)
    exec_command(com2, pip.com[1], env);
  else
    exec_pipe(com1, com2, env, pip.com);
}

void	my_pipe(t_shell sh, char **env, int j, t_pip pip)
{
  int	pipefd[2];
  char	*com1;
  char	*com2;

  pip = separate_pipe(sh.com[j], pip);
  if (pipe(pipefd) == -1)
    exit(3);
  if (dup2(1, pipefd[1]) == -1)
    exit(3);
  com1 = ret_total(sh, pip.com[0][0]);
  com2 = ret_total(sh, pip.com[1][0]);
  my_pipe2(com1, com2, pip, env);
  if (com1)
    free(com1);
  if (com2)
    free(com2);
}
