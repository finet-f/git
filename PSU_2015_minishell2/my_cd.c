#include "main.h"

void	my_chhome(char **env, char *path, t_cd cd)
{
  int	i;

  i = 7;
  while (env[cd.o][i])
    env[cd.o][i++] = 0;
  i = 4;
  while (env[cd.p][i])
    env[cd.p][i++] = 0;
  env[cd.o] = my_newstrcpy2(env[cd.o], cd.pwd, 7, 0);
  i = 0;
  while (env[cd.o][i])
    i++;
  if (env[cd.o][--i] == '/')
    env[cd.o][i] = 0;
  env[cd.p] = my_newstrcpy2(env[cd.p], path, 4, 0);
  chdir(path);
}

void	my_chdir2(char *path, t_cd cd, char **env)
{
  int	i;

  i = 0;
  if (path[0] == '/')
    my_chhome(env, path, cd);
  else
    {
      while (cd.pwd[i])
	i++;
      if (cd.pwd[--i] != '/')
	{
	  cd.pwd = my_realloc(cd.pwd, 1);
	  cd.pwd[++i] = '/';
	}
      my_chhome(env, my_strcat(cd.pwd, path), cd);
    }
}

void		my_chdir(char **env, char *path, t_cd cd)
{
  DIR		*dir;
  struct stat	buf;

  stat(path, &buf);
  if (access(path, F_OK) != -1)
    if (S_ISDIR(buf.st_mode))
      if ((dir = opendir(path)) != NULL)
	my_chdir2(path, cd, env);
      else
	{
	  my_pute(path);
	  my_pute(": Permission denied.\n");
	}
    else
      {
	my_pute(path);
	my_pute(": Not a directory.\n");
      }
  else
    {
      my_pute(path);
      my_pute(": No such file or directory.\n");
    }
  if (dir)
    closedir(dir);
}

void	my_cd(char **com, char **env)
{
  t_cd	cd;

  cd = searchenv(env, cd);
  if (!com[1])
    {
      cd = search_home(env, cd);
      if (!cd.home)
	my_pute("env: cd: No such file or directory\n");
      else
	my_chhome(env, cd.home, cd);
      return ;
    }
  if (cd.opwd == NULL || cd.pwd == NULL)
    {
      my_pute("env: cd: No such file or directory\n");
      return ;
    }
  if (my_strcmp(com[1], "-"))
    my_chdir(env, cd.opwd, cd);
  else
    my_chdir(env, com[1], cd);
}
