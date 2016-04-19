#include "main.h"

void	new_epur_str2(char *str, char *new, int *j, int *i)
{
  if (str[*i] == ';')
    {
      while (str[*i] == ';')
	(*i)++;
      if (new[*j - 1] != ' ')
	new[(*j)++] = ' ';
      new[(*j)++] = ';';
      new[(*j)++] = ' ';
      while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ';')
	(*i)++;
    }
  if (str[*i] == '|')
    {
      while (str[*i] == '|')
	(*i)++;
      if (new[*j - 1] != ' ')
	new[(*j)++] = ' ';
      new[(*j)++] = '|';
      new[(*j)++] = ' ';
      while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ';')
	(*i)++;
    }
}

int	new_epur_str1(char *str, char *new, int j, int i)
{
  while (str[i])
    {
      if (str[i] == '\t' || str[i] == ' ')
	{
	  new[j++] = ' ';
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      new_epur_str2(str, new, &j, &i);
      if (str[i])
	new[j++] = str[i++];
    }
  return (j);
}

char	*new_epur_str(char *str)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == ';')
    i++;
  if ((new = malloc(sizeof(char) * (my_strlen(str) * 2 + 10))) == NULL)
    exit(2);
  j = new_epur_str1(str, new, j, i);
  new[j] = 0;
  while (new[--j] == ';' || new[j] == ' ')
    new[j] = 0;
  return (new);
}
