/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:00:48 by pruangde          #+#    #+#             */
/*   Updated: 2022/04/08 01:55:35 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len = sp_strlen(s1, 0) + sp_strlen(s2, 0);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*sp_strdup_reloc(t_lstfd *data)
{
	size_t	new_len;
	size_t	len;
	char	*dup;
	char 	*tmp;
	size_t	mode;

	mode = (size_t)find_n(data->str);
	len = sp_strlen(data->str, mode);
	dup = (char *)malloc((len + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, data->str, len);
	dup[len] = '\0';
	new_len = sp_strlen((data->str + len), 0);
	tmp = (char *)malloc((new_len + 1) * sizeof(char));
	tmp = ft_memcpy(tmp, data->str + len, new_len);
	tmp[new_len] = '\0';
	free(data->str);
	data->str = tmp;
	free(tmp);
	tmp = NULL;
	return (dup);
}

void	rdline(t_lstfd *data)
{
	char	buf[BUFFER_SIZE + 1];

	data->rfd = read(data->fd, buf, BUFFER_SIZE);
	if (data->rfd < 0 || (data->rfd == 0 && !data->str))
	{
		data->str = NULL;
		return ;
	}
	buf[data->rfd] = '\0';
	data->str = ft_strjoin(data->str, buf);
	if (find_n(data->str))
			return ;
	while (data->rfd > 0)
	{
		data->rfd = read(data->fd, buf, BUFFER_SIZE);
		buf[data->rfd] = '\0';
		data->str = ft_strjoin(data->str, buf);
 		if (find_n(data->str))
			break ;
	}
	return ;
}

t_lstfd	*c_new_lst(int fd)
{
	t_lstfd	*new;

	new = (t_lstfd *)malloc(sizeof(t_lstfd));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->rfd = 0;
	new->str = (char *)malloc(1 * sizeof(char));
	new->next = NULL;
	return (new);
}

t_lstfd	*delstruct(t_lstfd *tmp)
{
	free(tmp->str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_lstfd	*data;
	t_lstfd			*tmp = NULL;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!data)
	{
		data = c_new_lst(fd);
		tmp = data;
	}
	else
	{
		//find fd in list
		tmp = data;
	}
	if (!(find_n(tmp->str)))
		rdline(tmp);
	ret = sp_strdup_reloc(tmp);
	if (!sp_strlen(ret, 0))
	{
		free(ret);
		ret = NULL;
	}
	if (tmp->rfd == 0 && !(tmp->str))
	{
		//new fx : 
		//free str + del list + sort list + if nothing left free all 
		free(tmp);
		tmp = NULL;
		data = NULL;
	}
	return (ret);
}


//**********   POINTER BEING FREED WAS NOT ALLOCATE