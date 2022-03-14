/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:00:48 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/14 08:07:15 by pruangde         ###   ########.fr       */
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
	while (s[i] || s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*ret;
	char		*buf;
	int			rfd;

	if (fd < 0)
		return (NULL);
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	rfd = read(fd, buf, BUFFER_SIZE);
	while (rfd > 0)
	{
		ft_strjoin(tmp, buf);
		if (find_n(tmp))
			break ;
		rfd = read(fd, buf, BUFFER_SIZE);
	}
	ret = sp_strdup_reloc(tmp);
	if (rfd == 0 && (sp_strlen(tmp, 0) == 0))
		free(tmp);
	free(buf);
	return (ret);
}
