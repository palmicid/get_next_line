/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:00:48 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/25 23:36:49 by pruangde         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		len = sp_strlen(s2, 0);
	else
		len = sp_strlen(s1, 0) + sp_strlen(s2, 0);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = s2[j];
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*sp_strdup_reloc(char *s)
{
	size_t	len;
	char	*dup;
	size_t	mode;

	mode = (size_t)find_n(s);
	len = sp_strlen(s, mode);
	dup = (char *)ft_calloc((len + 1), (sizeof(char)));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s, len);
	return (dup);
}

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*ret;
	char			buf[BUFFER_SIZE + 1];
	int				rfd;
	static	size_t	point;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rfd = read(fd, buf, BUFFER_SIZE);
	if (rfd < 0 || (rfd == 0 && !tmp))
	{
		tmp = NULL;
		return (NULL);
	}
	buf[rfd] = '\0';
	while (rfd > 0)
	{
		tmp = ft_strjoin(tmp, buf);
		if (find_n(tmp + point))
			break ;
		rfd = read(fd, buf, BUFFER_SIZE);
		buf[rfd] = '\0';
	}
	ret = sp_strdup_reloc(tmp + point);
	point += sp_strlen(ret, 0);
	if (!sp_strlen(ret, 0))
	{
		free(ret);
		ret = NULL;
	}
	if (rfd == 0 && (sp_strlen(tmp + point, 0) == 0))
	{
		free(tmp);
		tmp = NULL;
	}
	return (ret);
}
