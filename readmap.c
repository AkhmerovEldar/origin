#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (line = get_next_line(fd));
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return(width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while(nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (line = get_next_line(fd))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}