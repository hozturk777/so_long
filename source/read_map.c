#include "so_long.h"
#include <unistd.h>

char	**read_map(char *map_path)
{
	int	fd;
	char	*line;
	char	**map;
	char	*temp;
	char	*joined_map;

	fd = open(map_path, O_RDONLY);

	if (fd < 0)
		return (NULL);
	joined_map = NULL;
	
	// char *buff;
	// line = get_next_line(fd);
	// read(fd, buff, 100);
	// ft_printf("%s\n", buff);
	// exit(1);

	// char *buff;
	// line = get_next_line(fd);
	// joined_map = ft_strjoin(joined_map, line);
	// line = get_next_line(fd);
	// joined_map = ft_strjoin(joined_map, line);
	// line = get_next_line(fd);
	// joined_map = ft_strjoin(joined_map, line);
	// line = get_next_line(fd);
	// joined_map = ft_strjoin(joined_map, line);
	// line = get_next_line(fd);
	// joined_map = ft_strjoin(joined_map, line);
	// line = get_next_line(fd);
	// joined_map = ft_strjoin(joined_map, line);
	// ft_printf("%s\n", joined_map);
	// exit(1);

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