/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:54:08 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/16 14:16:26 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	get_length(char *str);
int	is_valid_base(char *base);
int	get_digit(char characters, char *base);
int	get_sign(char *number, int *index);

int	base_to_decimal(char *number, char *base )
{
	int	index;
	int	sign;
	int	result;
	int	digit;
	int	baselength;

	index = 0;
	result = 0;
	baselength = get_length(base);
	sign = get_sign(number, &index);
	while (number[index])
	{
		digit = get_digit(number[index], base);
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

void	revers_result(char *result, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = result[start];
		result[start] = result[end];
		result[end] = temp;
		start++;
		end--;
	}
}

char	*decimal_to_base(int number, char *base)
{
	char	*result;
	int		baselength;
	int		index;

	baselength = get_length(base);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_number;
	int		length;
	char	*result;

	if (!is_valid_base(base_to) || !is_valid_base(base_from))
		return (NULL);
	decimal_number = base_to_decimal(nbr, base_from);
	result = decimal_to_base(decimal_number, base_to);
	if (!result)
		return (0);
	length = get_length(result);
	if (result[0] == '-')
		revers_result(result, 1, length - 1);
	else
		revers_result(result, 0, length - 1);
	return (result);
}
/*
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

	result = ft_convert_base("1479280589", "0123456789", "01");
	printf("0123456789 (decimal) -> %s (binary)\n", result);
	free(result);

	return (0);
}*/
