#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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
	str[total_nbr] = '\0';
	i = total_nbr - 1;	
	str = malloc(total_nbr + 1);
	if (str == NULL)
		return NULL;
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
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
	int nb;
	scanf("%d",&nb);
	char *	str = ft_itoa(nb);
	write(1,str,strlen(str));
}
