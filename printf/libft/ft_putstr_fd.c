/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:39:29 by eproust           #+#    #+#             */
/*   Updated: 2024/10/05 15:01:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	return (write(fd, s, len));
}

/*
#include <stdio.h>

int	open_error()
{
	printf("Open error\n");
	return (1);
}

int	main(void)
{
	char *str = "Hello, World!";
	char *filename = "test.txt";
	char buf[1024];

	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (open_error());
	ft_putstr_fd(str, fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (open_error());
	int bytes_read = read(fd, buf, sizeof(buf));
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, sizeof(buf));
	}
	close(fd);

	return (0);
}
*/
