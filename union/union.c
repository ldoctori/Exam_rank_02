#include <unistd.h>

int	find(char *str, char ch)
{	
	int i = 0;

	while(str[i])
	{
		if(str[i] == ch)
			return (-1);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char	str[255];
	int	i = 1;
	int	j = 0;
	int	k = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{	
		j = 0;
		while (argv[i][j])
		{
			k = find(str, argv[i][j]);
			if (k != -1)
			{
				str[k] = argv[i][j];
				write(1, &str[k], 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return(0);
}
