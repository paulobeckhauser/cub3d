#ifndef CONTROLS_H
#define CONTROLS_H

#include "textures.h"

int	    close_game(const t_mlx *mlx);
void	init_hooks(t_mlx *mlx);
int    	keypress(int keysymbol, const t_mlx *mlx);

#endif //CONTROLS_H
