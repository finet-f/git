#ifndef MAIN_H_
# define MAIN_H_

void	end_game(int, char **);
int	check_is_end(char **);
void	replace_map(char **, int, int, t_tab);
void	ai_turn(char **, t_tab);
int	my_analysis_line(t_tab size,
			 char buff[R_SIZE],
			 char **map);
int	my_analysis_match(char buff[R_SIZE],
			  int line,
			  char **map);
char	**init_map(t_tab);
void	my_putstrtab(char **, int);
void	choose_turn(char **, t_tab, int *);

#endif /* !MAIN_H_ */
