/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:22:07 by aderison          #+#    #+#             */
/*   Updated: 2024/10/08 00:10:22 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_leaks.h"

void	*ft_leaks(size_t size, const char *name, int line)
{
	if (!name)
		return (ft_putstr_fd(YELLOW "➜ Invalid pointer name\n" RESET, 2), NULL);
	if(size <= 0)
		return (ft_putstr_fd(YELLOW "➜ Invalid pointer size\n" RESET, 2), NULL);
	line = 0;
	line++;
	return NULL;
}
