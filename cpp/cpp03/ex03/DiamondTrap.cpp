int	ft_atoi(char *str);
{
	int i;
	int j;
	i = 0;
	j = 0;
	while(str[i] != 0)
	{
		if (str[i] == " ")
			str[j] = str[i];
			j++;
			str[j] = '\0';
			return (str);
		if (str[i] == "-" && str[i] == "+")
			str[j] = str[i] % 2
			{
				if (str[i] == 1)
				str[i] = '-';
				return (str);
				if (str[i] == 0)
				str[i] = '\0';
				return (str);
			}
		if (str[i] >= '0' && str[i] <= '9')
			return (str + 48);
	i++;
	}
}