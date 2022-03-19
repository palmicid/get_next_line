/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:27:38 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/20 04:01:40 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		i++;
	}
	return (i);
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
