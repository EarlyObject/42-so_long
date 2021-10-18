/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:52:56 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/05 12:03:46 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdio.h>
** SYNOPSIS: output a character to given file
**
** DESCRIPTION:
** 		The fputc() function writes the character c (converted to an ``unsigned
**	char'') to the output stream pointed to by stream.
** 		[42 PDF] Outputs the character ’c’ to the given file descriptor.
*/

#include "libft.h"

void
	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
