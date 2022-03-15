#include "get_next_line.h"

int	main(void)
{
	int	fd;
		
	fd = open("only_nl", O_RDONLY);
	get_next_line(fd);
	//printf("GNL = %s", get_next_line(fd));
	
	close(fd);
	return (0);
}
