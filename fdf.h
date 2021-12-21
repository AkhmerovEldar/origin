#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct 
{
	int width;
	int	height;
	int	**z_matrix;
}		fdf;

void	read_file(char *file_name, fdf *data);
int		ft_wdcounter(char const *str, char c);

#endif