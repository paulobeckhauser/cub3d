#ifndef CONTROLS_H
#define CONTROLS_H

#include "structs.h"
#include "textures.h"

void    change_angle_left(t_game *game);
void    change_angle_right(t_game *game);
int	    close_game(t_game *game);
void	init_hooks(t_game *game);
int    	keypress(int keysymbol, t_game *game);
void    rotate_player_left(t_game *game);
void    rotate_player_right(t_game *game);

#endif //CONTROLS_H
