#include "so_long.h"
#include <unistd.h>

static int open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
	{
		ft_printf("file could not be opened");
		return (0);
	}
	return (fd);
}

char	**read_map(char *map_path)
{
	int	fd;
	char	*line;
	char	**map;
	char	*temp;
	char	*joined_map;

	fd = open_file(map_path);

	if (fd < 0)
		return (NULL);
	joined_map = NULL;

	while ((line = get_next_line(fd)))
	{
		temp = joined_map;
		joined_map = ft_strjoin(joined_map, line);
		if (temp)
			free(temp);
		free(line);
	}
	close(fd);
	
	if (!joined_map)
		return (NULL);
	
	map = ft_split(joined_map, '\n');
	free(joined_map);
	return (map);
}