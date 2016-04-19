#include "main.h"

int	count_com(char **com)
{
  int	i;
  int	l;

  i = 0;
  l = 0;
  while (com[i])
    if (com[i++][0] == ';')
      l++;
  return (++l);
}

int	count_line(char **com, int i)
{
  int	j;
  int	n;

  j = 0;
  n = 0;
  while (com[j])
    {
      if (com[j][0] == ';')
	{
	  n++;
	  j++;
	}
      if (n == i)
	{
	  n = 0;
	  while (com[j] && com[j++][0] != ';')
	    n++;
	  return (n);
	}
      j++;
    }
  return (0);
}

char	**divide_com1(int *j, char **com, int i)
{
  int	k;
  char	**new;

  if ((new = malloc(sizeof(char *) * count_line(com, i))) == NULL)
    exit(2);
  k = 0;
  while (com[*j] && com[*j][0] != ';')
    {
      if ((new[k] = malloc(my_strlen(com[*j]) + 1)) == NULL)
	exit(2);
      new[k] = my_strcpy(new[k], com[*j]);
      (*j)++;
      k++;
    }
  new[k] = NULL;
  if (com[*j] && com[*j][0] == ';')
    (*j)++;
  return (new);
}

char	***divide_com(char **com)
{
  char	***new;
  int	i;
  int	j;
  int	l;

  l = count_com(com);
  if ((new = malloc(sizeof(char **) * l)) == NULL)
    exit(2);
  i = 0;
  j = 0;
  while (i < l)
    {
      new[i] = divide_com1(&j, com, i);
      i++;
    }
  new[i] = NULL;
  return (new);
}
