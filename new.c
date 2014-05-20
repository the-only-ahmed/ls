/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 18:44:40 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/15 18:44:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		verif(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != 'l' && str[i] != 't'
				 && str[i] != 'a' && str[i] != 'r')
		{
			error(&str[i], 'b');
			return (0);
		}
		i++;
	}
	return (1);
}

void	suite(char *str, DIR *directory, char *ahmed)
{
	if (ft_strchr(str, 'l') && ft_strchr(str, 'r'))
		fn_list(directory, ahmed, 10);
	else if (ft_strchr(str, 'a') && ft_strchr(str, 'l'))
		fn_list(directory, ahmed, 11);
	else if (ft_strchr(str, 'a') && ft_strchr(str, 't'))
		lister(directory, ahmed, 12);
	else if (ft_strchr(str, 'a') && ft_strchr(str, 'r'))
		lister(directory, ahmed, 13);
	else if (ft_strchr(str, '1') && ft_strchr(str, 'a'))
		lister(directory, ahmed, 14);
	else if (ft_strchr(str, '1') && ft_strchr(str, 't'))
		lister(directory, ahmed, 15);
	else if (ft_strchr(str, '1') && ft_strchr(str, 'r'))
		lister(directory, ahmed, 16);
	else if (ft_strchr(str, '1'))
		lister(directory, ahmed, 17);
	else if (ft_strchr(str, 'a'))
		lister(directory, ahmed, 18);
	else if (ft_strchr(str, 'r'))
		lister(directory, ahmed, 19);
	else if (ft_strchr(str, 't'))
		lister(directory, ahmed, 20);
	else if (ft_strchr(str, 'l'))
		fn_list(directory, ahmed, 21);
}

void	ft_list(int i, int ac, char *option, char **av)
{
	DIR		*directory;

	av = tri(av, ac, 1, i);
	while (i < ac)
	{
		if ((directory = opendir(av[i])) != NULL)
		{
			if	(ac > 3)
			{
				ft_putstr(av[i]);
				ft_putendl(":");
			}
			flags(option, directory, av[i]);
		}
		else
		{
			error(av[i], 'a');
			directory = opendir(".");
			return ;
		}
		i++;
		if (i < ac)
			ft_putstr("\n");
	}
}