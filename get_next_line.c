/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:00:48 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/15 12:55:06 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//find \n ret 1 if found 
int	find_n(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*ret;
	char		buf[BUFFER_SIZE + 1];
	int			rfd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	rfd = read(fd, buf, BUFFER_SIZE);
	if (rfd < 0 || (rfd == 0 && !tmp))
	{
		tmp = NULL;
		return (NULL);
	}
	//----------------ok------------------------
	while (rfd > 0)
	{
		tmp = ft_strjoin(tmp, buf);
		if (find_n(tmp))
		{
			break ;
		}
		rfd = read(fd, buf, BUFFER_SIZE);
	}
	ret = sp_strdup_reloc(tmp);
	if (rfd == 0 && (sp_strlen(tmp, 0) == 0))
	{
		free(tmp);
		tmp = NULL;
	}
	return (ret);
}
