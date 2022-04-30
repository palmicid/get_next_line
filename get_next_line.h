/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:27 by pruangde          #+#    #+#             */
/*   Updated: 2022/04/30 20:02:46 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_lstfd
{
	int				fd;
	int				rfd;
	char			*str;
	struct s_lstfd	*next;
}					t_lstfd;

int		find_n(char *s);
char	*get_next_line(int fd);
char	*rdline(t_lstfd *cursor);
char	*sp_strdup_reloc(t_lstfd *data);
char	*sp_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	sp_strlen(const char *s, int mode);
t_lstfd	*new_or_find(t_lstfd *data, int fd);

#endif
