
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	do_word(char *str, int len)
{
	if (len == 0)
	{
		while (str[len] != ' ' && str[len] != '\0')
		{
			ft_putchar(str[len]);
			len++;
		}
		return ;
	}
	while (!(str[len + 1] == '\0' || str[len + 1] == ' '))
	{
		if (len != 0)
			ft_putchar(str[len + 1]);
		len++;
	}
	ft_putchar(' ');
}

int	main(int argc, char *argv[])
{
		int len;
		char *str;

	if (argc == 2)
	{
		str = argv[1];
		len = ft_strlen(str) - 1;
		while (len >= 0)
		{
			if (str[len] == ' ' || len == 0)
				do_word(str, len);
			len--;
		}
	}
	write(1, "\n", 1);
}
