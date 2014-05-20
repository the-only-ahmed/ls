/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 00:33:11 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/09 11:04:09 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	match(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		while (*(s2 - 1) == '*' && *s2 == *s1
			&& *s2 == *(s1 + 1) && *(s2 + 1) != *(s1 + 1))
			s1++;
		while (*s1 == *s2 && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '*')
		{
			s2++;
			s1--;
		}
		else if (*s1 != *s2 && *(s2 - 1) != '*')
			return (0);
		s1++;
	}
	if (*s2 == '\0' || (s1[0] == '\0' && *s2 == '*'))
		return (1);
	return (0);
}

void	flagless_ls(int ac, char **av, DIR *directory)
{
	int		i;
	char	**mat;

	i = 1;
	mat = (char**)malloc(sizeof(char) * ac);
	while (i < ac)
	{
		mat[i - 1] = ft_strdup(av[i]);
		i++;
	}
	mat = tri(mat, ac - 1, 22, 0);
	i = 0;
	while (i < ac - 1)
	{
		ahmed(i, mat, ac, directory);
		i++;
		if (i < ac - 1)
			ft_putstr("\n");
	}
}

void	ahmed(int i, char **mat, int ac, DIR *directory)
{
	char	*str;

	if (!check(i, mat, ac, directory))
	{
		directory = opendir(".");
		if (ft_strrchr(mat[i], '/') != NULL)
		{
			if (ac > 2)
			{
				ft_putstr(mat[i]);
				ft_putendl(":");
			}
			str = (char*)malloc(sizeof(char) * ft_strlen(mat[i]));
			ft_strncpy(str, mat[i], ft_strlen(mat[i]) - ft_strlen(ft_strrchr(mat[i], '/')));
			if ((directory = opendir(str)) == NULL)
				error(str, 'a');
			free(str);
		}
		lister_match(directory, mat[i]);
	}
}

int		check(int i, char **mat, int ac, DIR *directory)
{
	if ((directory = opendir(mat[i])) != NULL)
	{
		if (ac > 2)
		{
			ft_putstr(mat[i]);
			ft_putendl(":");
		}
		lister(directory, mat[i], 22);
		return (1);
	}
	return (0);
}