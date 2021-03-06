#include "get_next_line.h"

#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	count = 0;

	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*new_str;
	int	len = 0;
	int	i = 0;
	int	j = 0;

	len = ft_strlen(str) + ft_strlen(buff) + 1;
	new_str = malloc(len);
	if (!new_str)
		return (0);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buff[j])
	{
		new_str[i] = buff[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_read(int fd)
{
	char	*buff = malloc(3);
	int	rb;
	char	*str = malloc(1);
	char	*tmp;
	int	read_len = 2;

	str[0] = '\0';
	while ((rb = read(fd, buff, read_len)) > 0)
	{	
		if (rb == -1)
			return(0);
		buff[rb] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		if (!str)
			return (0);
		free(tmp);
		free(buff);
		read_len *= 2;
		buff = malloc(read_len + 1);
	}
	free(buff);
	return (str);
}

char	*ft_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (0);
}

char	*ft_strndup(char *str, int len)
{
	char	*new_str = malloc(len + 1);
	int	i = 0;

	if (!new_str)
		return (0);
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);

}

int	get_next_line(char **line)
{
	static char	*str;
	int		fd = 0;
	char		*n;
    
	if (!str)
	{
		str = ft_read(fd);
		if (!str)
			return (-1);
	}
	n = ft_strchr(str, '\n');
	if (n)
	{
		*line = ft_strndup(str, n - str);

		n++;
	        str = n;
		if (!(*line))
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strndup(str, ft_strchr(str, '\0') - str);
		if (!(*line))
			return (-1);
		return (0);
	}
}
