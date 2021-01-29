/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:29:04 by kgeorgia          #+#    #+#             */
/*   Updated: 2020/11/26 18:54:20 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_len_buff(char *buff)
{
	int			res;

	res = 0;
	if (buff)
		res = ft_strlen(buff);
	return (res);
}

static char		*join_str(char *buff, char *curr)
{
	char		*res;
	int			len1;
	int			len2;
	int			i;

	i = 0;
	len1 = ft_len_buff(buff);
	len2 = ft_len_buff(curr);
	res = malloc(len1 + len2 + 1);
	while (i < len1)
	{
		res[i] = buff[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		res[i] = curr[i - len1];
		i++;
	}
	res[i] = '\0';
	free(buff);
	ft_empty_str(curr, BUFFER_SIZE + 1);
	return (res);
}

static int		read_buff(char **buff, char **curr, char **line, int ret)
{
	int			len_line;
	char		*str;

	curr[0][ret] = '\0';
	*buff = join_str(*buff, *curr);
	len_line = end_line(*buff);
	if (len_line >= 0)
	{
		*line = ft_strdup(*buff);
		str = *buff;
		*buff = ft_strdup(str + len_line + 1);
		free(str);
		free(*curr);
		return (1);
	}
	free(*curr);
	return (0);
}

static int		ft_bad_input(int fd, char **line, char **curr)
{
	int ret;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*curr = ft_new_str(BUFFER_SIZE)))
		return (-1);
	if ((ret = read(fd, curr, 0)) < 0)
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*buff[10000];
	char		*curr;
	int			ret;

	if (ft_bad_input(fd, line, &curr) < 0)
		return (-1);
	while ((ret = read(fd, curr, BUFFER_SIZE)) > 0)
	{
		if (read_buff(&buff[fd], &curr, line, ret))
			return (1);
		curr = ft_new_str(BUFFER_SIZE);
	}
	if (read_buff(&buff[fd], &curr, line, 0))
		return (1);
	else if (ft_strlen(buff[fd]))
	{
		*line = ft_strdup(buff[fd]);
		free(buff[fd]);
		buff[fd] = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}
