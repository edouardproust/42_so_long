/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:55:29 by eproust           #+#    #+#             */
/*   Updated: 2024/09/17 13:51:19 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "Hello world!";
	int c = '\0';

	printf("string: \"%s\"\n", str);
	printf("char: \'%c\'\n", c);
	printf("ft_strchr: \"%s\"\n", ft_strchr(str, c));
	printf("strchr: \"%s\"\n", strchr(str, c));	

	return (0);
}
*/
