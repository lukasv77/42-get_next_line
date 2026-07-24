#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	test_file(const char *path, int calls)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	printf("=== %s ===\n", path);
	for (i = 0; i < calls; i++)
	{
		line = get_next_line(fd);
		printf("call %d: %p", i + 1, (void *)line);
		if (line)
			printf(" \"%s\"", line);
		printf("\n");
		free(line);
	}
	close(fd);
	printf("\n");
}

int	main(void)
{
	test_file("./tests/nl", 2);
	test_file("./tests/41_with_nl", 3);
	test_file("./tests/multiple_line_no_nl", 11);
	return (0);
}
