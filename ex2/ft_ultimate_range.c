/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 10:01:56 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/10 11:05:20 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	size;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	index = 0;
	while (min < max)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (size);
}
/*#include <stdio.h>

int main()
{
	int	*range;
	int x = ft_ultimate_range(&range, 10, 20);
	for(int i = 0; i < 10; i++)
		printf("%d\n",range[i]);
	printf("\nx=%d\n", x);
}*/
