/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:27 by pruangde          #+#    #+#             */
/*   Updated: 2022/04/08 09:15:49 by pruangde         ###   ########.fr       */
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
	int				rfd;
	char			*str;
	struct s_lstfd	*next;
}					t_lstfd;


char	*get_next_line(int fd);						// 
char	*rdline(t_lstfd *cursor);	// 
int		find_n(char *s);							// OK
size_t	sp_strlen(const char *s, int mode);			// OK

char	*sp_strdup_reloc(t_lstfd *data);			// OK
t_lstfd	*new_or_find(t_lstfd *data,int fd);
//t_lstfd *relist(t_lstfd *data, t_lstfd *tmp); 	bonus
char	*sp_strjoin(char *s1, char *s2);			// OK
void	*ft_memcpy(void *dest, const void *src, size_t n);


#endif
