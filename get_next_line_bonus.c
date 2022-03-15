#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	//static t_lstfd	*store;
	//t_lstfd			ptrlst;
	int				rfd;
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	rfd = read(fd, buf, BUFFER_SIZE);
	if (rfd < 0)
		return (NULL);
//---------------OK-----------------------
	
	return (0);
}
