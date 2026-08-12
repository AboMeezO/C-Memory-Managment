/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:54:08 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/13 00:47:12 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	getlength(char *str);
int	isvalidbase(char *base);
int	getdigit(char characters, char *base);
int	getsign(char *number, int *index);

int	base_to_decimal(char *number, char *base )
{
	int	index;
	int	sign;
	int	result;
	int	digit;
	int	baselength;

	index = 0;
	result = 0;
	baselength = getlength(base);
	sign = getsign(number, &index);
	while (number[index])
	{
		digit = getdigit(number[index], base);
		if (digit < 0)
			break ;
		result = result * baselength + digit;
		index++;
	}
	return (result * sign);
}

int	count_digits(int number, int baselength)
{
	int	digitcount;

	digitcount = 1;
	if (number < 0)
	{
		digitcount++;
		number = -number;
	}
	while (number >= baselength)
	{
		number /= baselength;
		digitcount++;
	}
	return (digitcount);
}

char	*decimal_to_base(int number, char *base)
{
	char	*result;
	int	baselength;
	int	index;

	baselength = getlength(base);
	result = malloc(sizeof(char)
		* (count_digits(number, baselength) + 1));
	if (!result)
		return (NULL);
	index = 0;
	if (number < 0)
	{
		result[index++] = '-';
		number = -number;
	}
	if (number == 0)
		result[index++] = base[0];
	while (number > 0)
	{
		result[index] = base[number % baselength];
		number /= baselength;
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	*ft_convert_base(char *number, char *base_from, char *base_to)
{
	int	decimalNumber;

	if (!isvalidbase(base_to) || !isvalidbase(base_from))
		return (NULL);
	decimalNumber = base_to_decimal(number, base_from);
	return (decimal_to_base(decimalNumber, base_to));

}

#include <stdio.h>
int	main(void)
{
	char	*result;

	result = ft_convert_base("101010", "01", "0123456789ABCDEF");
	printf("101010 (binary) -> %s (hex)\n", result);
	free(result);

	result = ft_convert_base("2A", "0123456789ABCDEF", "01");
	printf("2A (hex) -> %s (binary)\n", result);
	free(result);

	result = ft_convert_base("2431", "01234", "0123456789");
	printf("2431 (base 5) -> %s (decimal)\n", result);
	free(result);

	result = ft_convert_base("-42", "0123456789", "01");
	printf("-42 (decimal) -> %s (binary)\n", result);
	free(result);

	return (0);
}
