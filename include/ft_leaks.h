/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:25:30 by aderison          #+#    #+#             */
/*   Updated: 2024/10/08 01:04:15 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEAKS_H
#define FT_LEAKS_H

#include <unistd.h>
#include <stdlib.h>

//colors
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"


typedef struct s_alloc 
{
    void *ptr;
    size_t size;
    const char *name;
    int line;
    struct s_alloc *next;
} t_alloc;

extern t_alloc *ptrs;

int	fct_strlen(const char *str);
int	fct_putstr_fd(const char *str, int fd);
void ft_putalloc();
void	*ft_malloc(size_t size, const char *name, int line);
void ft_free(void *ptr);

#endif
