/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:56:28 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/10 09:16:09 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		index;
	char	*dup;

	index = 0;
	while (src[index])
		index++;
	dup = (char *)malloc(sizeof(char) * (index + 1));
	if (dup == NULL)
		return (NULL);
	index = 0;
	while (src[index])
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
/*#include <stdio.h>

int	main()
{
	char str[] = "you'll never know...";
	printf("originl: %s\n", str);
	printf("duplicated: %s\n", ft_strdup(str));
}*/
