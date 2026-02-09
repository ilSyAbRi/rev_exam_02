#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

long	count_nbr(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
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
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		i;
	long	total_nbr;
	char	*str;
	long	nbr_long;

	nbr_long = (long)nbr;
	total_nbr = count_nbr(nbr_long);
	i = total_nbr - 1;
	str = malloc(total_nbr + 1);
	if (str == NULL)
		return (NULL);
	str[total_nbr] = '\0';
	if (nbr_long == 0)
		str[0] = '0';
	else if (nbr_long < 0)
	{
		str[0] = '-';
		nbr_long = nbr_long * -1;
	}
	while (nbr_long != 0)
	{
		str[i] = (nbr_long % 10) + '0';
		nbr_long = nbr_long / 10;
		i--;
	}
	return (str);
}

int	main(void)
{
	int		nb;
	char	*str;

	scanf("%d", &nb);
	str = ft_itoa(nb);
	write(1, str, strlen(str));
	free(str);
	return (0);
}
