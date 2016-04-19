#ifndef MAIN_H_
# define MAIN_H_

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "my.h"

typedef struct	s_pip
{
  int		nb;
  int		*pos;
  int		nbcom;
  char		***com;
}		t_pip;

typedef struct	s_cd
{
  char		*home;
  char		*opwd;
  char		*pwd;
  int		h;
  int		o;
  int		p;
}		t_cd;

typedef struct	s_shell
{
  char		*user;
  char		**path;
  char		***com;
  char		*total;
}		t_shell;

void	my_pipe(t_shell, char **, int, t_pip);
int	count_l(char **, int);
t_pip	search_pipe(char **);
void	disp(char ***);
char	***divide_com(char **);
char	*new_epur_str(char *);
void	exec_command(char *, char **, char **);
void	exec_pipe(char *, char *, char **, char ***);
char	**my_unsetenv(char **, char **);
char	**realloc_env(char **, int);
char	**realloc_env2(char **, int);
char	*ret_name(char *);
char	**my_setenv(char **, char **);
t_cd	search_home(char **, t_cd);
t_cd	searchenv(char **, t_cd);
char	*my_newstrcpy2(char *, char *, int, int);
void	my_cd(char **, char **);
char	*my_newstrcpy(char *, int, int);
void	prompt(t_shell, char **);
void	my_pute(char *);
char	**search_built_in(char **, char **);
char	**my_str_to_tab(char *);
t_shell	deter_path(char **, t_shell);
t_shell	deter_user(char **, t_shell);

#endif /* !MAIN_H_ */
