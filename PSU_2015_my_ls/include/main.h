#ifndef MAIN_H_
# define MAIN_H_

typedef struct dirent t_dirent;
typedef struct stat t_stat;

void	my_ls1(char *, int *);
void	my_ls3(int, char **, int, int *);
void	check_error(int, char **);
int	deter_start(int *, char **);

#endif /* !MAIN_H_ */
