#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int ft_strlen(char *arr)
{
	int i = 0;

	while (arr[i])
		i++;
	return (i);
}

int	main()
{	
	int 	MAX = 1000000;
	int	r;
	int	i = 0;
	int	fd = open("./HUGE.txt",O_RDWR|O_CREAT|O_TRUNC, 0644);
	char	arr[] = "1234567890-=qwertyui\nop[]	\asdfghjk\nl;'zxcvbnm,./!@	#$%^&*()_+|?QWERTYU	I\nOP[]ASDFGHJKL;'ZXCVBNM,./";
	int	len = ft_strlen(arr);
	while (i < MAX)
	{	
		r = rand() % len;
		write(fd, &arr[r], 1);
		i++;
	}
	close(fd);
}
