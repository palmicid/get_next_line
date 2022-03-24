/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 04:00:20 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/24 00:39:14 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*gnl;

	fd = open("43_no_nl", O_RDONLY);
	for (int i = 0; i < 1; i++)
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
