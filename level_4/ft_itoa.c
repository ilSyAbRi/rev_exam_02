#include <stdlib.h>

void	ft_putchar(int nb)
{
	write(1,nb,1);
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
	str[total_nbr - 1] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	i++;
	}
}

int	main()
{
	int	nb = ft_itoa(nbr);
	ft_putnbr(nb);
}
