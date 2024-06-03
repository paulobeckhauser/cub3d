#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H
#include "structs.h"

void	calc_new_ray_x_y(t_game *game);
void	draw_collision(const t_game *game, double x_iterator, double y_iterator);
void	draw_map(t_game *game);
void	draw_player(const t_game *game);
void	draw_ray(t_game *game);
void	init_test_map(t_game *map);
void	load_images(t_game *textures);
void	move_player_backward(t_game *game);
void    move_player_forward(t_game *game);

#endif //RAYCASTER_TEST_H
