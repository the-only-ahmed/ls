/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 13:12:56 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/12 19:26:10 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**tri(char **str, int n, int a, int x)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	if (x)
		i = x;
	while (i < n)
	{
		tmp = ft_strdup(str[i]);
		j = i;
		while (j > 0 && ((REV && REV_COND) || SORT))
		{
			str[j] = ft_strdup(str[j - 1]);
			j--;
		}
		str[j] = ft_strdup(tmp);
		i++;
	}
	return (str);
}

char	**tri_time(char **str, int n, struct stat stats, int r)
{
	int				i;
	int				j;
	char			*tmp;
	int				a;

	i = 1;
	while (i < n)
	{
		tmp = ft_strdup(str[i]);
		j = i;
		lstat(tmp, &stats);
		a = stats.st_mtime;
		lstat(str[j - 1], &stats);
		while (j > 0 && (SORT_T || (a > stats.st_mtime)))
		{
			str[j] = ft_strdup(str[j - 1]);
			j--;
			lstat(str[j - 1], &stats);
		}
		str[j] = ft_strdup(tmp);
		i++;
	}
	return (str);
}
