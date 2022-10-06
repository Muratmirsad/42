int	ft_atoi(char *str)
{
	int index;
	int nb;
	int x;

	index = 0;
	while (9 <= (str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == 43)
		index++;
	x = 1;
	else if (str[index] == 45)
	{
		x = -1;
		index++;
	}
	nb = 0;
	while (48 <= str[index] && str[index] <= 57)
	{
		nb = nb * 10;
		nb = nb + (str[index] - 48);
		index++;
	}
	return (nb * x);
}
