/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:21:05 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/13 15:29:59 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	copy_sep(char *sep, char *result, int *outer_index)
{
	int	sep_index;

	sep_index = 0;
	while (sep[sep_index])
	{
		result[*outer_index] = sep[sep_index];
		(*outer_index)++;
		sep_index++;
	}
}

void	strjoiner(char **strs, char *sep, char *result, int size)
{
	int	index;
	int	inner_index;
	int	outer_index;

	index = 0;
	outer_index = 0;
	while (index < size)
	{
		inner_index = 0;
		while (strs[index][inner_index])
		{
			result[outer_index] = strs[index][inner_index];
			outer_index++;
			inner_index++;
		}
		if (index < size - 1)
			copy_sep(sep, result, &outer_index);
		index++;
	}
	result[outer_index] = '\0';
}

void	length_counter(int size, char **strs, char *sep, int *counter)
{
	int	index;
	int	inner_index;
	int	sep_len;

	index = 0;
	*counter = 0;
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	while (index < size)
	{
		inner_index = 0;
		while (strs[index][inner_index])
			inner_index++;
		*counter += inner_index;
		index++;
	}
	if (size > 1)
		*counter += (size - 1) * sep_len;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		final_length;
	char	*result;

	final_length = 0;
	length_counter(size, strs, sep, &final_length);
	result = (char *)malloc(sizeof(char) * (final_length + 1));
	if (!result)
		return (NULL);
	if (size <= 0)
	{
		result[0] = '\0';
		return (result);
	}
	strjoiner(strs, sep, result, size);
	return (result);
}
/*#include <stdio.h>
int	main(void)
{
	char	*result;
	char	*strs1[] = {"Over", "and", "over"};
	char	*strs2[] = {"i", "keep", "going"};
	char	*strs3[] = {"over"};
	char	*strs4[] = {"", "the ", "", "world"};
	char	*strs5[] = {"we", "knew"};

	result = ft_strjoin(3, strs1, ", ");
	printf("Test 1: %s\n", result);
	free(result);

	result = ft_strjoin(3, strs2, "-");
	printf("Test 2: %s\n", result);
	free(result);

	result = ft_strjoin(1, strs3, ", ");
	printf("Test 3: %s\n", result);
	free(result);

	result = ft_strjoin(4, strs4, " | ");
	printf("Test 4: %s\n", result);
	free(result);

	result = ft_strjoin(2, strs5, "");
	printf("Test 5: %s\n", result);
	free(result);

	result = ft_strjoin(0, NULL, ", ");
	printf("Test 6: \"%s\"\n", result);
	free(result);

	return (0);
}*/
