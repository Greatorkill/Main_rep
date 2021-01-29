/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:57:24 by kgeorgia          #+#    #+#             */
/*   Updated: 2020/11/28 14:09:50 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 63
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
void	ft_empty_str(char *s, size_t n);
char	*ft_new_str(size_t size);
int		end_line(char *buff);
char	*ft_strdup(const char *s1);

#endif
