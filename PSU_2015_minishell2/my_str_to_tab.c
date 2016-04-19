#include "main.h"

int	count_word(char *str)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while (str[i])
    {
      while (str[i] != ':' && str[i])
	i++;
      if (str[i] == ':')
	i++;
      nb++;
    }
  return (i);
}

char	**my_str_to_tab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * count_word(str))) == NULL)
    exit(2);
  while (str[j])
    {
      if ((tab[i] = malloc(sizeof(char) * 201)) == NULL)
	exit(2);
      k = 0;
      while (str[j] != ':' && str[j])
	tab[i][k++] = str[j++];
      tab[i][k] = 0;
      if (str[j] == ':')
	j++;
      i++;
    }
  return (tab);
}
