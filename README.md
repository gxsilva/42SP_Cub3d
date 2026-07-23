# 42SP Cub3d

Cub3d is a 42SP graphics project that recreates a simple first-person view using raycasting. The program reads a 2D `.cub` map file, validates its configuration, and renders the scene in a window with textured walls, player movement, and keyboard-driven camera control.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Bash Script](https://img.shields.io/badge/Bash%20Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-4EAA25?style=for-the-badge&logo=gnu-make&logoColor=white)

## 📚 Table of Contents

- [✨ Features](#features)
- [🚀 Quick Start](#quick-start)
- [🛠 Installation](#installation)
- [🎬 Demo](#demo)
- [🧱 Project Structure](#project-structure)
- [🎁 Bonus](#bonus)
- [🆘 Support](#support)

## ✨ Features

- Raycasting-based 3D rendering from a 2D map
- Map parsing and validation for textures, colors, and walls
- Player movement, turning, and mouse-driven interaction hooks
- Separate mandatory and bonus builds
- Sample maps for valid and invalid scenarios

## 🚀 Quick Start

1. Clone the repository and enter the project directory.
    ```bash
    git clone https://github.com/gxsilva/42SP_Cub3d.git
    cd 42SP_Cub3d
    ```
2. Initialize the bundled submodules.
    ```bash
    git submodule update --init --recursive
    ```
3. Install the Linux dependencies required by MLX42.
    ```bash
    sudo apt update
    sudo apt install build-essential cmake libx11-dev libglfw3-dev libglfw3 xorg-dev
    ```
4. Build the project.
    ```bash
    make
    ```
5. Run the program with a valid map.
    ```bash
    ./cub3D maps/good/test_map.cub
    ```

## 🛠 Installation

This repository is intended to be built on Linux. The project depends on `gcc`, `make`, `cmake`, GLFW, and the local MLX42, libft, and GNL submodules.

### Required packages

For Debian-based systems:
```bash
sudo apt update
sudo apt install build-essential cmake libx11-dev libglfw3-dev libglfw3 xorg-dev
```

For Arch-based systems:
```bash
sudo pacman -S glfw-x11
```

### Build steps

1. Clone the repository.
    ```bash
    git clone https://github.com/gxsilva/42SP_Cub3d.git
    cd 42SP_Cub3d
    ```
2. Fetch all submodules.
    ```bash
    git submodule update --init --recursive
    ```
3. Build the mandatory version.
    ```bash
    make
    ```
4. Optionally build the bonus version.
    ```bash
    make bonus
    ```

The main build produces `cub3D`. The bonus target produces `cub3D_bonus`. Additional targets available in the Makefile include `make clean`, `make fclean`, `make re`, `make debug`, `make leak`, and `make norm`.

## 🧱 Project Structure

- `src/` contains the application code.
- `src/map/` handles file parsing, map data, validation, and rendering helpers.
- `src/player/` contains player state and initialization logic.
- `src/mlx/` contains the MLX42 window, hook, and input setup.
- `src/sprites/` handles sprite loading and rendering.
- `src/utils/` contains general utility helpers.
- `src/error/` centralizes error handling.
- `src/free/` contains cleanup and memory-release helpers.
- `src/debug/` contains debug-only helpers used by the debug build.
- `includes/` holds the public project headers.
- `lib/libft/` is the custom libft submodule.
- `lib/GNL/` is the get_next_line submodule.
- `lib/MLX42/` is the graphics library submodule.
- `maps/good/` contains valid sample maps.
- `maps/bad/` contains invalid sample maps for parser checks.
- `textures/` stores texture assets used by the game.
- `sprites/` stores sprite assets used by the game.
- `scripts/` contains helper scripts for local testing and leak checks.

## 🎁 Bonus

The bonus build expands the project with additional gameplay and rendering features. In this repository, that includes a minimap, interactive doors, transparent elements, animated characters, custom textures, and mouse support.

These bonus features are implemented across the rendering, sprite, and input code paths, and are built with:

- `src/map/draw/render_doors.c` for door rendering
- `src/sprites/render_sprite.c` and `src/sprites/sprite.c` for animated sprites and textures
- `src/mlx/mlx_mouse.c` for mouse-driven rotation

## 🆘 Support

If the project fails to build or run, first confirm that the submodules are initialized, the Linux packages are installed, and the map file ends with a valid `.cub` configuration. For map rules and expected behavior, the canonical reference is `SUBJECT.md`. For graphics-library details, refer to the bundled MLX42 documentation in `lib/MLX42/`.

This project is maintained for educational use at 42SP. There is no dedicated support channel in the repository, so the most reliable way to troubleshoot is to compare your map against the sample files in `maps/good/` and `maps/bad/`.
