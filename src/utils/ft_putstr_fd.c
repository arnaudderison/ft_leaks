/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:34:47 by aderison          #+#    #+#             */
/*   Updated: 2024/10/07 23:04:43 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_leaks.h"

int	ft_putstr_fd(const char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}
