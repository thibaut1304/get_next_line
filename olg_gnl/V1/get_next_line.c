/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:19:05 by thhusser          #+#    #+#             */
/*   Updated: 2020/11/24 21:19:05 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_return(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
		tmp = ft_strdup(&(*str)[i + 1]);
	free(*str);
	*str = tmp;
	if (!*str)
		return (0);
	return (1);
}

int		readline(int fd, char **str, char **buff)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	while ((res = read(fd, *buff, BUFFER_SIZE)) > 0)
	{
		(*buff)[res] = 0;
		tmp = ft_strjoin(*str, *buff);
		free(*str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (res);
}

int		ft_error(char *buff)
{
	free(buff);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int				res;
	static char		*str;
	char			*buff;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff || read(fd, buff, 0) < 0)
		return (ft_error(buff));
	res = readline(fd, &str, &buff);
	free(buff);
	if (res < 0)
		return (-1);
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	res = ft_return(&str, line);
	return (res);
}
