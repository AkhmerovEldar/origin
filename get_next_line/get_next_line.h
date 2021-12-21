/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:20:59 by ranuytte          #+#    #+#             */
/*   Updated: 2021/08/14 14:33:42 by raph             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl_data
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;
}t_gnl_data;

typedef struct s_trim_data
{
	int		len;
	char	*line;
	char	*tmp;
}t_trim_data;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);

#endif
