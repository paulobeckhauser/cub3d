#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H
#include "structs.h"

void	calc_new_ray_x_y(t_game *game);
void	draw_map(t_game *game);
void	draw_player(const t_game *game);
void	draw_ray(t_game *game);
void	init_test_map(t_game *map);
void	load_images(t_game *textures);
void    move_player(t_game *game);

#endif //RAYCASTER_TEST_H
