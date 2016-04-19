#include "main.h"

void	disp(char ***com)
{
  int	i;
  int	j;

  i = 0;
  while (com[i])
    {
      j = 0;
      while (com[i][j])
	my_printf("[%s]\n", com[i][j++]);
      my_printf("\n");
      i++;
    }
}

char	*ret_name(char *str)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(2);
  i = 0;
  while (str[i] && str[i] != '=')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  return (new);
}

char	*my_newstrcpy(char *str, int j, int i)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 10))) == NULL)
    exit(2);
  while (str[j])
    new[i++] = str[j++];
  new[i] = 0;
  return (new);
}

char	*my_newstrcpy2(char *str, char *str1, int i, int j)
{
  str = my_realloc(str, my_strlen(str1));
  while (str1[j])
    str[i++] = str1[j++];
  str[i] = 0;
  return (str);
}

void	my_pute(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(2, &str[i++], 1);
}
