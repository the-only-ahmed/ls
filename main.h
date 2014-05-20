/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:43:08 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/12 19:01:18 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

# define SORT (ft_strcmp(str[j - 1], tmp) > 0)
# define REV (ft_strcmp(str[j - 1], tmp) < 0)
# define REV_COND (a == 4 || a == 5 || a == 6 || a == 10 || a == 13 \
					|| a == 16 || a == 19)
# define SORT_T (a < stats.st_mtime && (!r || r == 1 || r == 2 || r == 5 \
				|| r == 8))
#define ALL (a == 0 || a == 1 || a == 3 || a == 4 || a == 6 || a == 7 \
			|| a == 11 || a == 12 || a == 13 || a == 14 || a == 18)

void	ft_ls(int ac, char **av, DIR *directory);
void	lister(DIR *directory, char *ch, int a);
void	flags(char *c, DIR *directory, char *ahmed);
int		match(char *s1, char *s2);
void	lister_match(DIR *directory, char *str);
void	error(char *str, char c);
void	flagless_ls(int ac, char **av, DIR *directory);
char	**tri(char **str, int n, int a, int x);
void	timing(char *str, DIR *directory, int r);
void	fn_list(DIR *directory, char *ch, int a);
void	affiche_permission(struct stat stats);
char	**raccourci(DIR *directory, char *ch, int a, int *i);
char	*reglage(char *str);
char	**tri_time(char **str, int n, struct stat stats, int r);
char	**string(DIR *directory, char *ch, int a, int *i);
void	ahmed(int i, char **mat, int ac, DIR *directory);
int		check(int i, char **mat, int ac, DIR *directory);
int		verif(char *str);
void	suite(char *str, DIR *directory, char *ahmed);
void	ft_list(int i, int ac, char *option, char **av);

#endif /* FT_LS_H  */
