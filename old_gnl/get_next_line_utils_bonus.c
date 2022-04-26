/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:27:38 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/15 04:16:20 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

//mode 1 find \n , mode 0 just \0
size_t	sp_strlen(const char *s, int mode)
{
	size_t	i;

	i = 0;
	if (mode == 0)
	{
		while (s[i] != '\0')
			i++;
	}
	else
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else
		len = sp_strlen(s1, 0) + sp_strlen(s2, 0);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

//mode 1 find \n , mode 0 just \0
char	*sp_strdup_reloc(char *s)
{
	size_t	len;
	char	*dup;
	char	*tempo;
	size_t	mode;
	//size_t	st;

	mode = (size_t)find_n(s);
	len = sp_strlen(s, 1) + 1;
	dup = (char *)ft_calloc((len + mode), (sizeof(char)));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s, len + mode);
	tempo = (char *)ft_calloc(sp_strlen((s + len), 0), sizeof(char));
	tempo = ft_memcpy(tempo, s + len, sp_strlen(s + len, 0));
	free(s);
	s = tempo;
	free(tempo);
	return (dup);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	len;
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	len = count * size;
	i = 0;
	while (i < len)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
