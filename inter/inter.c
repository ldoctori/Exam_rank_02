#include <unistd.h>

int	find(char *str, char ch)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == ch)
			return (-1);
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	char	str[255];
	int	i = 0;
	int	j = 0;
	int	k = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	while (argv[1][j])
	{
		if (find(argv[2], argv[1][j]) == -1)
		{
			k = find(str, argv[1][j]);
			if (k != -1)
			{
				str[k] = argv[1][j];
				write(1,&str[k],1);
			}
		}
		j++;
	}
	write(1,"\n", 1);
	return (0);
}
