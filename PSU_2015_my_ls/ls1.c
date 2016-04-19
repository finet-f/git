#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "ls1.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <pwd.h>
#include <grp.h>

void		my_ls1(char *av, int *tab)
{
  DIR		*dirp;
  t_dirent	*entry;

  dirp = opendir(av);
  if (dirp == NULL)
    {
      my_printf("ls: cannot access %s: No such file or directory\n", av);
      exit(1);
    }
  if (tab[3] == 1)
    option_r(av, tab);
  else
    {
      entry = readdir(dirp);
      while (entry != NULL)
	{
	  if (entry->d_name[0] != '.')
	    option_l(entry->d_name, tab, av);
	  entry = readdir(dirp);
	}
    }
  closedir(dirp);
}
