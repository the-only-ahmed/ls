/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 12:07:40 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/12 19:18:01 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**raccourci(DIR *directory, char *ch, int a, int *i)
{
	DIR				*repertoire;
	struct dirent	*lecture;
	char			**str;

	*i = 0;
	repertoire = opendir(ch);
	while ((lecture = readdir(repertoire)) != NULL)
		if (lecture->d_name[0] != '.' || ALL)
			(*i)++;
	str = (char**)malloc(sizeof(char) * (200000));
	*i = 0;
	while ((lecture = readdir(directory)) != NULL)
		if (lecture->d_name[0] != '.' || ALL)
		{
			str[*i] = ft_strjoin(ft_strjoin(ch, "/"), 
				ft_strdup(lecture->d_name));
			(*i)++;
		}
	return (str);
}

char	*reglage(char *str)
{
	char	*s;

	s = ft_strsub(str, ft_strchr(str, ' ') - str,
		ft_strrchr(str, ':') - ft_strchr(str, ' '));
	return (s);
}
