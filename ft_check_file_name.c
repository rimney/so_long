/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:40:30 by rimney            #+#    #+#             */
/*   Updated: 2021/12/14 19:43:13 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strrchr(char *str, char c)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_filename_is_valid(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_filename(char *name)
{
	char	*str;

	str = ft_strrchr(name, '.');
	if (!ft_filename_is_valid(name))
		return (0);
	if (ft_strcmp(str, ".ber") != 0)
		return (0);
	return (1);
}
