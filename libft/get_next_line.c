/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:31:01 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/24 10:52:29 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				verdict(char **line)
{
	if (!**line)
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char file[MAX_FD][BUFF_SIZE + 1];
	char		*buf;
	char		*pos;
	int			ret;

	buf = file[fd];
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		pos = ft_strchr(buf, 10);
		if (pos)
		{
			*line = ft_strjoinfree(*line, buf, pos - buf, 1);
			ft_strncpy(buf, &buf[pos - buf + 1], BUFF_SIZE - (pos - buf));
			return (1);
		}
		*line = ft_strjoinfree(*line, buf, BUFF_SIZE, 1);
		ret = read(fd, file[fd], BUFF_SIZE);
		buf[ret] = '\0';
		if (!ret)
			return (verdict(line));
	}
}
