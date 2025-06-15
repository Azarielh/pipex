#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		fd[ac - 1];
	char	*lines[ac - 1];
	int		files_left;
	int		i;

	if (ac == 1)
		return ("You forgot to input arguments");

	files_left = 0;
	for (i = 1; i < ac; i++)
	{
		fd[i - 1] = open(av[i], O_RDONLY);
		if (fd[i - 1] == -1)
		{
			lines[i - 1] = get_next_line(fd[i - 1]);
			printf("File %d: %s\n", i, lines[i - 1]);
			continue ;
		}
		lines[i - 1] = get_next_line(fd[i - 1]);
		if (!lines[i - 1])
		{
			printf("File %d is empty or reading failed.\n", i);
			lines[i - 1] = get_next_line(fd[i - 1]);
			printf("File %d: %s\n", i, lines[i - 1]);        
			close(fd[i - 1]);
			files_left--;
		}
		else
			files_left++;
	}
	while (files_left > 0)
	{
		for (i = 0; i < ac - 1; i++)
		{
			if (lines[i])
			{
				printf("File %d: %s", i, lines[i]);
				free(lines[i]);
				lines[i] = get_next_line(fd[i]);
				if (!lines[i])
				{
					close(fd[i]);
					files_left--;
				}
			}
		}
	}
	return (0);
}
