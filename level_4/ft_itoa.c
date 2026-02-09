#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1,"-",1);
		nb = nb * -1;
	}
	if (nb > 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	count_nbr(int	nbr)
{
	int	count = 0;
	if (nbr == 0)
		return 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		count++;
	}
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return count;
}


char	*ft_itoa(int nbr)
{
	int	i;
	int total_nbr ;
	char *str ;
	total_nbr = count_nbr(nbr);
	str = malloc(total_nbr + 1);
	str[total_nbr] = '\0';
	i = total_nbr - 1;
	while (nbr != 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	i--;
	}
	return str;
}

int	main()
{
	char *	str = ft_itoa(1234);
	write(1,str,4);
}
