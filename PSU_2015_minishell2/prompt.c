#include "main.h"

int	prompt3(t_shell sh, int j, char **env)
{
  if ((sh.com[j][0][0] == '.' && sh.com[j][0][1] == '/')
      || sh.com[j][0][0] == '/')
    {
      if (access(sh.com[j][0], F_OK) != -1)
	{
	  if (access(sh.com[j][0], X_OK) != -1)
	    exec_command(sh.com[j][0], sh.com[j], env);
	  else
	    {
	      my_pute(sh.com[j][0]);
	      my_pute(": Permission denied.\n");
	    }
	  return (1);
	}
      else
	return (0);
    }
  return (0);
}

void	prompt2(t_shell sh, char **env, int j)
{
  int	m;
  int	i;

  m = 0;
  i = 0;
  if (prompt3(sh, j, env))
    return ;
  while (sh.path[i] && m == 0)
    {
      sh.total = my_strcat(sh.path[i], sh.com[j][0]);
      if (access(sh.total, F_OK) != -1 && access(sh.total, X_OK) != -1)
	m = 1;
      if (m == 0)
	free(sh.total);
      i++;
    }
  if (m == 1)
    exec_command(sh.total, sh.com[j], env);
  else if (m == 0)
    {
      my_pute(sh.com[j][0]);
      my_pute(": Command not found.\n");
    }
}
 
char	**prompt1(t_shell sh, char **env)
{
  int	j;
  t_pip	pip;
  char	**tmp;

  j = 0;
  while (sh.com[j])
    {
      pip = search_pipe(sh.com[j]);
      if (pip.nb > 0)
	my_pipe(sh, env, j, pip);
      else if ((tmp = search_built_in(sh.com[j], env)) != NULL)
	env = tmp;
      else
	prompt2(sh, env, j);
      j++;
    }
  return (env);
}

void	prompt(t_shell sh, char **env)
{
  char	*com;

  sh = deter_user(env, sh);
  sh = deter_path(env, sh);
  (sh.user[0] != '$') ? my_printf("%s > ", sh.user) : my_printf("Anonymous > ");
  com = NULL;
  com = my_get_next_line(0);
  if (com == NULL)
    my_putstr_error("[ERROR]\n", 0);
  sh.com = divide_com(my_str_to_word_tab((com = new_epur_str(com))));
  if (!com[0])
    {
      free(com);
      free(sh.com);
      prompt(sh, env);
      return ;
    }
  env = prompt1(sh, env);
  prompt(sh, env);
}
