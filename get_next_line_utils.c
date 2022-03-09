/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:27:38 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/09 20:42:53 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sp_strdup(char *s)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = sp_strlen(s);
	dup = (char *)malloc((len + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		*((unsigned char *)dup + i) = *((unsigned char *)s + i);
		i++;
	}
	return (dup);
}

size_t	sp_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' || s[i] != '\0')
		i++;
	return (i);
}

char	*sp_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j:
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
