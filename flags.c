/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 13:13:06 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/12 19:04:40 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fn_list(DIR	*directory, char *ch, int a)
{
	struct stat		stats;
	char			**str;
	int				i;
	int				j;

	str = string(directory, ch, a, &i);
	j = 0;
	while (j < i)
	{
		if (lstat(str[j], &stats) < 0)
			error(str[j], 'a');
		else
		{	
			affiche_permission(stats);
			ft_putstr("	");
			ft_putstr(reglage(ctime(&(stats.st_mtime))));
			ft_putstr("	");
			ft_putstr(ft_strsub(str[j], ft_strrchr(str[j], '/') - str[j] + 1, ft_strlen(str[j])));
			if (j < i - 1)
				ft_putchar('\n');
		}
		j++;
	}
}

char	**string(DIR *directory, char *ch, int a, int *i)
{
	char	**str;
	int		j;
	int		x;
	struct stat		stats;

	x = 0;
	str = raccourci(directory, ch, a, i);
	if (a == 0 || a == 2 || a == 3 || a == 9)
		str = tri_time(str, *i, stats, a);
	else
		str = tri(str, *i, a, 0);
	j = 0;
	while (j < *i)
	{
		if (lstat(str[j], &stats) >= 0)
			x += stats.st_blocks;
		j++;
	}
	ft_putstr("total ");
	ft_putnbr(x);
	ft_putchar('\n');
	return (str);
}

void	affiche_permission(struct stat stats)
{
	struct passwd	*passent;
	struct group	*grp;

	ft_putchar((S_ISDIR(stats.st_mode)) ? 'd' : '-');
	ft_putchar((stats.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((stats.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((stats.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((stats.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((stats.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((stats.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((stats.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((stats.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((stats.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("	");
	ft_putnbr(stats.st_nlink);
	ft_putstr("	");
	passent = getpwuid(stats.st_uid);
	ft_putstr(passent->pw_name);
	ft_putstr("	");
	grp = getgrgid(stats.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr("	");
	ft_putnbr(stats.st_size);
}

void	timing(char *ch, DIR *directory, int r)
{
	char			**str;
	struct stat		stats;
	int				i;
	int				j;

	str = raccourci(directory, ch, 0, &i);
	str = tri_time(str, i, stats, r);
	j = 0;
	while (j < i)
	{
		ft_putstr(ft_strsub(str[j], ft_strrchr(str[j], '/') - str[j] + 1, ft_strlen(str[j])));
		ft_putstr("	");
		j++;
	}
}
