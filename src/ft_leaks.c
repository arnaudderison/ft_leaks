/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:22:07 by aderison          #+#    #+#             */
/*   Updated: 2024/10/08 01:58:08 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_leaks.h"

static t_alloc *new_alloc(void *ptr, size_t size, const char *name, int line)
{
    t_alloc *new = malloc(sizeof(t_alloc));
    if (!new)
        return NULL;
    *new = (t_alloc){ptr, size, name, line, NULL};
    return new;
}

static void add_alloc(t_alloc *ptrs, t_alloc *new)
{
	t_alloc *tmp;

	if(!new)
	{
		fct_putstr_fd(BLUE "➜ Internal error\n" RESET, 2);
		return ;
	}
	if(!ptrs)
	{
		ptrs = new;
		return ;
	}
	tmp = ptrs;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;

}

void	*ft_malloc(size_t size, const char *name, int line)
{
	static t_alloc	ptrs;
	t_alloc			*new;
	void *ptr;

	if (!name)
		return (fct_putstr_fd(YELLOW "➜ Invalid pointer name\n" RESET, 2), NULL);
	if (size <= 0)
		return (fct_putstr_fd(YELLOW "➜ Invalid pointer size\n" RESET, 2), NULL);
	if (line < 0)
		return (fct_putstr_fd(YELLOW "➜ Invalid line\n" RESET, 2), NULL);
	ptr = malloc(size);
	if(!ptr)
		return (fct_putstr_fd(RED "➜ Malloc failed\n" RESET, 2), NULL);
	new = new_alloc(ptr, size, name, line);
	if (!new)
    {
        free(ptr);
		ptr = NULL;
        return (fct_putstr_fd(RED "➜ New alloc failed\n" RESET, 2), NULL);
    }
	add_alloc(&ptrs, new);
	return (ptr);
}
