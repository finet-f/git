#include <dirent.h>
#include <sys/types.h>
#include "option_r.h"
#include <stdlib.h>
#include "my.h"

void		option_r1(int i, char **files, int *tab, char *path)
{
  i--;
  while (i >= 0)
    {
      option_l(files[i], tab, path);
      i--;
    }
}

void		option_r(char *path, int *tab)
{
  DIR		*dirp;
  t_dirent	*entry;
  char		**files;
  int		i;

  i = 0;
  dirp = opendir(path);
  entry = readdir(dirp);
  files = malloc(sizeof(char *) * 1001);
  while (entry != NULL)
    {
      if (entry->d_name[0] != '.')
	{
	  files[i] = malloc(sizeof(char) * 301);
	  files[i] = my_strcpy(files[i], entry->d_name);
	  i++;
	}
      entry = readdir(dirp);
    }
  option_r1(i, files, tab, path);
  free(files);
  closedir(dirp);
}
