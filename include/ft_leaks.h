/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:25:30 by aderison          #+#    #+#             */
/*   Updated: 2024/10/07 23:53:50 by aderison         ###   ########.fr       */
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
    char *name;
    int line;
    struct s_alloc *next;
} t_alloc;

int	ft_strlen(const char *str);
int	ft_putstr_fd(const char *str, int fd);
void	*ft_leaks(size_t size, const char *name, int line);

#endif
