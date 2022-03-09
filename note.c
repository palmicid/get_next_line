/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:12:11 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/09 20:42:58 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function malloc new space for buf
{

}

find \n

//sp_strjoin(char *s1, char *s2);	create new and del old s1

type_yungMaiRoo sai_do_while()
{
	//sp_strlen --> \n || \0
	//strnjoin
}

char	*get_next_line(int fd)
{
	int			rfd;	//read fd
	char		*str;	//for return
	static char	*tmp;	
	//store if more than one line | store all at tmp || 2D for bonus
	char		*buf;	//read

	//cx tmp[fd] if not NULL jump to last process
	//cx fd
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//go to malloc
	//do the same as inside while
	//sp_strchr --> find \n || \0
	//copy from buf to tmp
	//
	//while (read(fd, buf, BUFFER_SIZE) > 0)
	//break if find \n / \0
	//transfer (tmp with same fd to str)
	//transfer from buf to tmp + free(buf)
	//free all if read || rfd == 0
	//cx str if still have something left 
	//|- find \n add front to str + del from tmp
	//return (str);
}

from old file
char	*get_next_line(int fd)
{
	int	rfd;
	char	*buf;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rfd = read(fd, buf, BUFFER_SIZE);
	if (rfd == -1)
		return (NULL);
	buf[BUFFER_SIZE + 1] = '\0';
	str = ft_strjoin(str,buf);

	while (read(fd, buf, BUFFER_SIZE) > 0)
	{

	}
}
