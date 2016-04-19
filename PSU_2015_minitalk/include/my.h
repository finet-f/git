#ifndef MY_H_
# define MY_H_

int	my_strcmp(char *, char *);
void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, char *src);
void	my_printf(char *, ...);
void	my_putstr_error(char *str, int statut);
char	*get_next_line(const int);
char	*my_realloc(char *, int);
char	*my_strcat(char *, char *);
char	**my_str_to_word_tab(char *);

#endif /* !MY_H_ */
