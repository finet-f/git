#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "options.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void	disp_rights(t_stat buf)
{
  if (S_ISLNK(buf.st_mode))
    my_putchar('l');
  else if (S_ISDIR(buf.st_mode))
    my_putchar('d');
  else
    my_putchar('-');
  my_printf((buf.st_mode & S_IRUSR) ? "r" : "-");
  my_printf((buf.st_mode & S_IWUSR) ? "w" : "-");
  my_printf((buf.st_mode & S_IXUSR) ? "x" : "-");
  my_printf((buf.st_mode & S_IRGRP) ? "r" : "-");
  my_printf((buf.st_mode & S_IWGRP) ? "w" : "-");
  my_printf((buf.st_mode & S_IXGRP) ? "x" : "-");
  my_printf((buf.st_mode & S_IROTH) ? "r" : "-");
  my_printf((buf.st_mode & S_IWOTH) ? "w" : "-");
  my_printf((buf.st_mode & S_IXOTH) ? "x " : "- ");
}

char	*deter_fullpath(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*str;

  j = 0;
  str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
  str = my_strcpy(str, str1);
  i = my_strlen(str1);
  if (str[i - 1] != '/')
    {
      str[i] = '/';
      i++;
    }
  while (str2[j] != '\0')
    {
      str[i] = str2[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}

void	deter_last_modif(char *month, int *day, char *hour, char *time)
{
  int	i;
  int	j;

  j = 4;
  while (i < 3)
    {
      month[i] = time[j];
      i++;
      j++;
    }
  month[i] = '\0';
  *day = time[9] - '0';
  if (time[8] >= '0' && time[8] <= '9')
    *day = *day + (time[8] - '0') * 10;
  j = 11;
  i = 0;
  while (i < 5)
    {
      hour[i] = time[j];
      i++;
      j++;
    }
  hour[i] = '\0';
}

void		option_l(char *filename, int *tab, char *path)
{
  t_stat	buf;
  t_passwd	*user;
  t_group	*grp;
  int		day;
  char		*month;
  char		*hour;

  month = malloc(sizeof(char) * 4);
  hour = malloc(sizeof(char) * 6);
  if (tab[0] == 1)
    {
      lstat(deter_fullpath(path, filename), &buf);
      user = getpwuid(buf.st_uid);
      grp = getgrgid(buf.st_gid);
      disp_rights(buf);
      deter_last_modif(month, &day, hour, ctime(&buf.st_mtime));
      my_printf("%d %s %s ", buf.st_nlink, user->pw_name, grp->gr_name);
      my_printf("%d %s %d ", buf.st_size, month, day);
      my_printf("%s %s\n", hour, filename);
      free(month);
      free(hour);
    }
  else
    my_printf("%s\n", filename);
}
