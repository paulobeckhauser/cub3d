#ifndef CONTROLS_H
#define CONTROLS_H

#include "structs.h"
#include "textures.h"

int	    close_game(t_game *game);
void	init_hooks(t_game *game);
int    	keypress(int keysymbol, t_game *game);

#endif //CONTROLS_H
