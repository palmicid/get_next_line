/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:26:05 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/09 20:43:01 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	in_while_proc(int *rfd, char *buf, )
{
	
}*/
//ret 1 --> found \n || \0 not last str pos
//ret 0 --> found \0 at last str pos
int	cx_nnul(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
		i++;
	if (i == BUFFER_SIZE)
		return (0);
	else
		return (i);
}

char	*relocate(char *str)
{
	
}

char	*get_next_line(int fd)
{
	int			cx;
	int			rfd;
	char		*buf[BUFFER_SIZE + 1];
	char		*str;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	rfd = read(fd, buf, BUFFER_SIZE);
	while (rfd > 0)
	{
		tmp = sp_strjoin(str, buf);
		cx = nnul(tmp)
		if (cx)
			break ;
		rfd = read(fd, buf, BUFFER_SIZE);
	}
	str = sp_strdup(tmp);
	if (cx)	
		tmp = relocate(tmp);
	else

	return (str);
}
