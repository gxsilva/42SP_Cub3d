# 42SP_Cub3d

Cub3d is a project from 42SP that introduces students to basic 3D graphics programming using raycasting, similar to early first-person shooter games like Wolfenstein 3D. The goal is to render a simple 3D environment from a 2D map.

## Features

- Raycasting engine for 3D rendering
- Player movement and rotation
- Basic wall textures and map parsing

## Getting Started

1. Clone the repository:
    ```bash
    git clone https://github.com/gxsilva/42SP_Cub3d.git
    ```
2. Initialize submodules:
    ```bash
    git submodule update --init --recursive
    ```
3. Build the project:
    ```bash
    make
    ```
4. Run the program with a map file:
    ```bash
    ./cub3d maps/example.cub
    ```

## Requirements

- Linux environment
- `gcc` compiler
- `cmake` compiler
- `make`
- MiniLibX graphics library

## License

This project is for educational purposes at 42SP.
