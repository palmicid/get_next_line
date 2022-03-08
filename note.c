/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:12:11 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/08 23:54:53 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function malloc new space for buf
{

}

char	*get_next_line(int fd)
{
	int			rfd;	//read fd
	char		*str;	//for return
	static char	*tmp;	//store if more than one line | store all at tmp
	char		*buf;	//read

	//cx fd
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//cx buf if not null cont strjoin / if not go to malloc
	//do the same as inside while
	//while (read(fd, buf, BUFFER_SIZE) > 0)
	//break if find \n / \0
	//transfer (tmp with same fd to str)
	//
	//return (str);
}
