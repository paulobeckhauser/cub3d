# cub3d Project

![cub3d](https://github.com/paulobeckhauser/cub3d/blob/main/bonus/textures/gif/cub3d.gif)

Welcome to the cub3d project. This project is a 3D engine inspired by the classic game Wolfenstein 3D. The bonus part of this project includes additional features and enhancements over the mandatory part. This README will guide you through the steps to compile and run the bonus part of the project, including key bindings for an immersive gameplay experience.

## Prerequisites (Linux only)
Before compiling the project, you need to set up the mlx library used for rendering. You can run prepared build script:

```./build_cub3d.sh```

## Running the Project
After compilation, you can run the project by executing the generated binary:

```./cub3d maps_testing_progress/good/preview.cub```

## Key Bindings

__Move Forward/Backward:__ W and S keys

__Strafe Left/Right:__ A and D keys

__Rotate View:__ Left and Right arrow keys or move the mouse

__Shoot:__ Left mouse click

__Open/Close Doors:__ E key

## Cleaning Up
To clean up the object files and the executable, you can use the following commands:

To remove object files:

```make clean```

To remove object files and the executable:

```make fclean```

Re-compiling
If you need to re-compile the project (for example, after making changes to the source code), you can use the following command:

```make re bonus```

This command will clean up the previous compilation and compile the project again.
