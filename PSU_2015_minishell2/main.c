#include "main.h"

void	exec_command(char *total, char **com, char **env)
{
  pid_t	cpid;
  int	s;

  cpid = fork();
  wait(&s);
  if (cpid == 0)
    execve(total, com, env);
  kill(cpid, 9);
  if (WIFSIGNALED(s))
    if (WTERMSIG(s) == 11)
      my_pute("Segmentation fault\n");
}

void	exec_pipe(char *com1, char *com2, char **env, char ***com)
{
  pid_t	cpid;
  int	pipefd[2];

  pipe(pipefd);
  cpid = fork();
  wait(NULL);
  if (cpid == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      execve(com1, com[0], env);
    }
  kill(cpid, 9);
  close(pipefd[1]);
  dup2(pipefd[0], 0);
  execve(com2, com[1], env);
}

void	ctrlc()
{
  my_printf("\n$> ");
}

int		main(int ac, char **av, char **env)
{
  t_shell	sh;

  signal(SIGINT, ctrlc);
  prompt(sh, env);
  return (0);
}
