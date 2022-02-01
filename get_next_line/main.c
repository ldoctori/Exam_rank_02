#include "get_next_line.h"
#include "get_next_line.c"

#include <stdio.h>
int main()
{
	char	*line;
	int	rb;

	while ((rb = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	
	printf("%s", line);
	free(line);
	line = NULL;
}
