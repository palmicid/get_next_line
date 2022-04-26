/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:27 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/24 23:45:11 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <fcntl.h>

typedef struct s_lstfd
{
	int				fd;
	char			*str;
	size_t			pos;
	struct s_lstfd	*next;
}	t_lstfd;


char	*get_next_line(int fd);
int		find_n(char *s);


size_t	sp_strlen(const char *s, int mode);
char	*ft_strjoin(char *s1, char *s2);
char	*sp_strdup_reloc(char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
