/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:42:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/12 19:35:53 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_ls(int ac, char **av, DIR *directory)
{
	int		i;
	int		j;
	int		x;
	char	*option;

	i = 1;
	j = 0;
	x = 0;
	option = (char*)malloc(sizeof(char) * 5);
	while (av[i] && av[i][0] == '-' && av[i][x + 1] != '\0')
	{
		option[j] = av[i][x + 1];
		j++;
		x++;
		if (av[i][x + 1] == '\0')
		{	
			i++;
			x = 0;
		}
	}
	option[j] = '\0';
	if (i == ac)
		flags(option, directory, ".");
	else
		ft_list(i, ac, option, av);
}

void	flags(char *str, DIR *directory, char *ahmed)
{
	if (!verif(str))
		return ;
	if (ft_strchr(str, 'a') && ft_strchr(str, 'l') && ft_strchr(str, 't') && ft_strchr(str, 'r'))
		fn_list(directory, ahmed, 0);
	else if (ft_strchr(str, '1') && ft_strchr(str, 'a') && ft_strchr(str, 'r') && ft_strchr(str, 't'))
		lister(directory, ahmed, 1);
	else if (ft_strchr(str, 'l') && ft_strchr(str, 'r') && ft_strchr(str, 't'))
		fn_list(directory, ahmed, 2);
	else if (ft_strchr(str, 'a') && ft_strchr(str, 'l') && ft_strchr(str, 't'))
		fn_list(directory, ahmed, 3);
	else if (ft_strchr(str, 'a') && ft_strchr(str, 'l') && ft_strchr(str, 'r'))
		fn_list(directory, ahmed, 4);
	else if (ft_strchr(str, '1') && ft_strchr(str, 'r') && ft_strchr(str, 't'))
		lister(directory, ahmed, 5);
	else if (ft_strchr(str, '1') && ft_strchr(str, 'a') && ft_strchr(str, 'r'))
		lister(directory, ahmed, 6);
	else if (ft_strchr(str, '1') && ft_strchr(str, 't') && ft_strchr(str, 'a'))
		lister(directory, ahmed, 7);
	else if (ft_strchr(str, 'r') && ft_strchr(str, 't'))
		lister(directory, ahmed, 8);
	else if (ft_strchr(str, 'l') && ft_strchr(str, 't'))
		fn_list(directory, ahmed, 9);
	suite(str, directory, ahmed);
}

void	lister(DIR *directory, char *ch, int a)
{
	char	**str;
	int		j;
	int		i;

	str = raccourci(directory, ch, a, &i);
	str = tri(str, i, a, 0);
	j = 0;
	while (j < i)
	{
		ft_putstr(ft_strsub(str[j], ft_strrchr(str[j], '/') - str[j] + 1, ft_strlen(str[j])));
		if (a == 1 || a == 5 || a == 6 || a == 7 || a == 14 || a == 15 || a == 16 || a == 17)
			ft_putchar('\n');
		else
			ft_putstr("	");
		j++;
	}
}

void	lister_match(DIR *directory, char *str)
{
	struct dirent	*lecture;
	int				i;
	char			*path;

	i = 0;
	while ((lecture = readdir(directory)) != NULL)
	{
		path = ft_strrchr(str, '/');
		if (path == NULL)
			path = ft_strdup(str);
		else
			path++;
		if (match(lecture->d_name, path))
		{
			if (lecture->d_name[0] != '.' || path[0] == '.')
			{
				ft_putstr(lecture->d_name);
				ft_putstr("	");
			}
			i++;
		}
	}
	if (i == 0)
		error(path, 'a');
}

void	error(char *str, char c)
{
		if (c == 'a')
		{
			ft_putstr("ft_ls: ");
			ft_putstr(str);
			ft_putendl(": No such file or directory");
		}
		else
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(*str);
			ft_putchar('\n');
			ft_putstr("usage: ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
			ft_putstr(" [file ...]");
		}
}
