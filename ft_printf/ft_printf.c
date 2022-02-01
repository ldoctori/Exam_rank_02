#include "ft_printf.h"

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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

int	ft_putnstr(char *str, int n)
{	
	int	i = 0;
	
	while (str[i] && i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{	
	if (!src)
		return (0);

	int	src_len = ft_strlen(src);
	char	*copy = malloc(src_len + 1);
	int	i = 0;

	if (copy == NULL)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);

}

char	*ft_s(va_list ap)
{
	char	*new_str;
	char	*buff;
	
	buff = va_arg(ap, char*);
	if (!buff)
        new_str = ft_strdup("(null)");
    else
        new_str = ft_strdup(buff);
	return (new_str);
}

char	*ft_itoa_hex(unsigned int n)
{
	char		*new_str;
	unsigned int	n_buff;
	int		count = 0;
	char	base[] = "0123456789abcdef";

	n_buff = n;
	if (n_buff == 0)
		count++;
	while (n_buff)
	{
		n_buff /= 16;
		count++;
	}
	new_str = malloc(count);
	if (!new_str)
		return (0);
	new_str[count] = '\0';
	count--;
	while (count >= 0)
	{	
		new_str[count] = base[n % 16];
		n /= 16;
		count--;
	}
	return (new_str);

}

char	*ft_x(va_list ap)
{
	char	*new_str;
	int	buff;

	buff = va_arg(ap, int);
	new_str = ft_itoa_hex(buff);
	return (new_str);
}

char	*ft_itoa(int n)	
{
	char	*new_str;
       	int	n_buff;
        int     count = 0;

        n_buff = n;
        while (n_buff)
        {
		n_buff /= 10;
		count++;
	}
     	if (n < 0 || n == 0)
		count++;
        new_str = malloc(count);
	if (!new_str)
		return (0);
        new_str[count] = '\0';
        count--;
	if (n >= 0)
		while (count >= 0)
        	{
			new_str[count] = n % 10 + '0';
			n /= 10;
			count--;
       		}
	else
	{
		while (count > 0)
		{
			new_str[count] = n % 10 * (-1) + '0';
			n /= 10;
			count--;
		}
		new_str[count] = '-';
	}
        return (new_str);

}

char *ft_d(va_list ap)
{
	char	*new_str;
	int	buff;
	buff = va_arg(ap, int);
	new_str = ft_itoa(buff);
	return (new_str);
}

unsigned int	ft_atoi(char *str)
{	
	unsigned int	n = 0;
	int		i = 0;

	while (*str >= '0' && *str <= '9')
	{
		n = n*10 + (str[i] - '0');
		str++;
	}
	return (n);
}

char	*ft_dot(char *str, char *new_str, int *len, int prec_len)
{	
	char	*tmp;
	int	i = 0;
	int	j = 0;
    
	if (*str == 's')
	{
		if (*len > prec_len)
			*len = prec_len;
		return (new_str);
	}
	if (*str == 'd' || *str == 'x')
	{
		if (*new_str == '-' && *len - 1 < prec_len)
		{	
			tmp = new_str;
			new_str = malloc(prec_len);
			new_str[0] = tmp[0];
			i++;
			while (i <= prec_len - *len + 1)
			{
				new_str[i] = '0';
				i++;
			}
			j++;
			while (j < *len)
			{
				new_str[i] = tmp[j];
				j++;
				i++;
			}
			new_str[i] = '\0';
			free(tmp);
			*len = prec_len + 1;
			return (new_str);
		}
		else if (*len < prec_len)
		{
			tmp = new_str;
			new_str = malloc(prec_len);
			while (i < prec_len - *len)
			{	
				new_str[i] = '0';
				i++;
			}
			while (j < *len)
			{
				new_str[i] = tmp[j];
				j++;
				i++;
			}
			new_str[i] = '\0';
			free(tmp);
			*len = prec_len;
			return (new_str);
		}
	}
	return (new_str);

}

int	ft_conv(char *str, va_list ap)
{	
	char	*new_str;
	int	len = 0;
	int	width = 0;
	int	i = 0;
	int	prec = 0;	
	int	prec_len;

	if (*str >= '0' && *str <= '9')
	{
		width = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str == '.')
	{
		str++;
		prec++;
		prec_len = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str == 's')
		new_str = ft_s(ap);
	if (*str == 'x')
		new_str = ft_x(ap);
	if (*str == 'd')
		new_str = ft_d(ap);
	len = ft_strlen(new_str);
	if (prec == 1)
		new_str = ft_dot(str, new_str, &len, prec_len);
	if (len >= width)
	{
		ft_putnstr(new_str, len);
		free(new_str);
		return (len);
	}
	while (i < width - len)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnstr(new_str, len);
	free(new_str);
	return (width);
}

int	ft_printf_helper(va_list ap, char *str)
{
	char	*ptr;
	int	len = 0;

	while (*str)
	{
		ptr = ft_strchr(str, '%');
		if (ptr)
		{
			len += ft_putnstr(str, ptr - str);
			str = ptr + 1;
			len += ft_conv(str, ap);
		}
		else
		{
			len += ft_putnstr(str, ft_strchr(str, '\0') - str);
			break ;
		}
		while (*str >= '0' && *str <= '9')
			str++;
		if (*str == '.')
		{
			str++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
		str++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int	len;

	va_start(ap, str);
	len = ft_printf_helper(ap, (char *)str);
	va_end(ap);
	return (len);
}
