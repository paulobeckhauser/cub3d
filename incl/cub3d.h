#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx;


int parser(void);

#endif