/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:45:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/13 00:46:31 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	getlength(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	isvalidbase(char *base)
{
	int	index;
	int	compare_index;

	if (getlength(base) < 2)
		return (0);
	index = 0;
	while (base[index])
	{
		if (base[index] == '+' || base[index] == '-'
			|| base[index] <= 32)
			return (0);
		compare_index = index + 1;
		while (base[compare_index])
		{
			if (base[compare_index] == base[index])
				return (0);
			compare_index++;
		}
		index++;
	}
	return (1);
}

int	getdigit(char characters, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == characters)
			return (index);
		index++;
	}
	return (-1);
}

int	getsign(char *number, int *index)
{
	int	sign;

	sign = 1;
	while (number[*index] == ' '
		|| (number[*index] >= 9 && 13 >= number[*index]))
		(*index)++;
	while (number[*index] == '+' || number[*index] == '-')
	{
		if (number[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}
