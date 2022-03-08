/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:26:05 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/08 23:55:07 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	for_malloc

char	*get_next_line(int fd)
{
	int		rfd;
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
	str = ft_strjoin(str, buf);
	
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		

	}
}
