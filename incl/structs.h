#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_line
{
	int             idx;
	char            *sprites;
	int             len;
	struct s_line    *prev;
	struct s_line    *next;
}   t_line;

typedef struct s_game
{
	void    *mlx_ptr;
	void    *win_ptr;
	int		img_x;
	int		img_y;
	void    *txt_floor;
	void    *txt_player;
	void    *txt_wall;
	int     map_line_count;
	t_line  *map_line;
	double	map_x;
	double	map_y;
	double	player_x;
	double	player_y;
	int		player_marked;
	double	ray_x;
	double	ray_y;
	double	player_angle;
}	t_game;

#endif //STRUCTS_H