/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 04:00:20 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/25 20:03:59 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*gnl;

	fd = open("multiple_line_with_nl", O_RDONLY);
	for (int i = 0; i < 7; i++)
	{
		gnl = get_next_line(fd);
		printf("txt = %s", gnl);
		//printf("\n-------------------------------------------\n");
		free(gnl);
	}
	close(fd);
	gnl = NULL;
	//free(gnl);
	return (0);
}
