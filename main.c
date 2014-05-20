/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:33:52 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/09 11:47:11 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int ac, char **av)
{
	DIR		*directory;

	if ((directory = opendir(".")) == NULL)
		return (-1);
	if (ac == 1)
		lister(directory, ".", 22);
	else if (av[1][0] != '-')
		flagless_ls(ac, av, directory);
	else
		ft_ls(ac, av, directory);
	ft_putchar('\n');
	if (closedir(directory) == -1)
		return (-1);
	return (0);
}
