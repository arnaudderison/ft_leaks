/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:33:01 by aderison          #+#    #+#             */
/*   Updated: 2024/10/08 01:47:22 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_leaks.h"

void ft_free(void *ptr)
{
    t_alloc *current;
    t_alloc *prev;

    current = ptrs;
    prev = NULL;
    if (!ptr)
    {
        ft_putstr_fd(YELLOW "➜ Attempt to free NULL pointer\n" RESET, 2);
        return;
    }

    while (current)
    {
        if (current->ptr == ptr)
        {
            if (prev)
                prev->next = current->next;
            else
                ptrs = current->next;
            free(current->ptr);
            current->ptr = NULL;
            free(current);
            current = NULL;
            return;
        }
        prev = current;
        current = current->next;
    }
    free(ptr);
    ptr = NULL;
    ft_putstr_fd(RED "➜ Attempt to free untracked pointer (free success)\n" RESET, 2);
}
