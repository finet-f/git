#ifndef MAIN_H_
# define MAIN_H_

void	check_error(int, char **);
int	find_littlest(int *, int);
void	exec_ra(int *, int tab[3], int, int *);
int	*exec_pb(int *, int *, int *tab_k[2], int);
int	*exec_pa(int *, int *, int *tab_k[2], int);
int	*pb(int *, int *, int *, int *);
int	*pa(int *, int *, int *, int *);

#endif /* !MAIN_H_ */
