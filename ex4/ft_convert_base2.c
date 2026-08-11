/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:45:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/11 17:31:27 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*hexaToDecimal(char *number)
{
	char	result;
	char	hex;
	char	index;

	hex = "0123456789abcdef";
	index = 0;
	while (number[index])
	{
		result[index] = hex[number[index] / 16];
		index++;
	}
	return (result);
}
