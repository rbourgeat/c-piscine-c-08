/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:24:27 by rbourgea          #+#    #+#             */
/*   Updated: 2019/09/12 13:14:00 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char				*ft_strdup(char *src)
{
	int			i;
	int			len;
	char		*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*src) * (len + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str		*table;
	int						i;

	i = 0;
	if (!(table = malloc((sizeof(struct s_stock_str) * (ac + 1)))))
		return (0);
	while (i < ac)
	{
		table[i].size = ft_strlen(av[i]);
		table[i].str = av[i];
		table[i].copy = ft_strdup(av[i]);
		i++;
	}
	table[i].str = 0;
	return (table);
}
