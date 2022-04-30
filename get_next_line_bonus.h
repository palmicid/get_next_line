/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:26:54 by pruangde          #+#    #+#             */
/*   Updated: 2022/05/01 04:28:06 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
t_lstfd	*create_list(int fd);
t_lstfd	*new_or_find(t_lstfd *data, int fd);
t_lstfd	*list_reloc(t_lstfd *data, int fd);

#endif
