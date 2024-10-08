/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:55:46 by aderison          #+#    #+#             */
/*   Updated: 2024/10/08 02:04:45 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_leaks.h"

static int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	ft_int_len(int n)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		len++;
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)(n);
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static int	ft_putnbr_fd(int nb, int fd)
{
	int				len;
	unsigned int	num;

	len = ft_int_len(nb);
	if (nb < 0)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		num = (unsigned int)(-nb);
	}
	else
		num = (unsigned int)(nb);
	if (num >= 10)
	{
		if (ft_putnbr_fd(num / 10, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd(num % 10 + '0', fd) < 0)
		return (-1);
	return (len);
}

void ft_putalloc()
{
    t_alloc *tmp;

    if(!ptrs)
        fct_putstr_fd(BLUE "➜ No malloc\n" RESET, 1);
    tmp = ptrs;
    while (tmp)
    {
        fct_putstr_fd(BLUE "Name: " RESET, 1);
        fct_putstr_fd(tmp->name, 1);
        fct_putstr_fd(BLUE " Line: " RESET, 1);
        ft_putnbr_fd(tmp->line, 1);
        fct_putstr_fd("\n", 1);
        tmp = tmp->next;
    }
    fct_putstr_fd("\n", 1);
}
