/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 07:33:42 by mohammah          #+#    #+#             */
/*   Updated: 2026/08/13 18:51:18 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_separator(char character, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (character == charset[index])
			return (1);
		index++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	index;
	int	count;
	int	is_word;

	index = 0;
	count = 0;
	is_word = 0;
	while (str[index])
	{
		if (is_separator(str[index], charset))
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count++;
		}
		index++;
	}
	return (count);
}

int	get_word_length(char *str, int start, char *charset)
{
	int	length;

	length = 0;
	while (str[start + length]
		&& !is_separator(str[start + length], charset))
		length++;
	return (length);
}

char	*copy_word(char *str, int start, int length)
{
	int		index;
	char	*word;

	word = malloc(sizeof(char) * length + 1);
	index = 0;
	while (index < length)
	{
		word[index] = str[start + index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words_count;
	int		index_string;
	int		index_word;
	int		length;

	words_count = count_words(str, charset);
	result = malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (0);
	index_string = 0;
	index_word = 0;
	while (str[index_string])
	{
		while (str[index_string] && is_separator(str[index_string], charset))
			index_string++;
		if (!str[index_string])
			break ;
		length = get_word_length(str, index_string, charset);
		result[index_word] = copy_word(str, index_string, length);
		index_word++;
		index_string += length;
	}
	result[index_word] = 0;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**result;
	int		index;

	result = ft_split("But, all of that was!!
	ripped .apart ,when you refused to fight", ",!");
	index = 0;
	while (result[index])
	{
		printf("[%s]\n", result[index]);
		free(result[index]);
		index++;
	}
	free(result);
	return (0);
}*/
