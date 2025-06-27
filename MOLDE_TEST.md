# MOLDE_TEST

## Validation file

### Invalid Input Examples

Below are some example commands demonstrating invalid input scenarios for `cub3d`:

- **No arguments provided**
    ```sh
    ./cub3d
    ```

- **More than one argument**
    ```sh
    ./cub3d random.cub random.cub
    ```

- **Invalid file extension**
    ```sh
    ./cub3d random.txt
    ```

- **Missing file extension**
    ```sh
    ./cub3d random
    ```

- **Multiple valid file extensions**
    ```sh
    ./cub3d file.cub.cub.cub
    ```
- **Invalid RGB color values**
    ```sh
    ./cub3D maps/bad/color_invalid_rgb.cub
    ```

- **Missing color definition**
    ```sh
    ./cub3D maps/bad/color_missing.cub
    ```

- **Missing ceiling RGB color**
    ```sh
    ./cub3D maps/bad/color_missing_ceiling_rgb.cub
    ```

- **Missing floor RGB color**
    ```sh
    ./cub3D maps/bad/color_missing_floor_rgb.cub
    ```

- **No color information**
    ```sh
    ./cub3D maps/bad/color_none.cub
    ```

- **Empty file**
    ```sh
    ./cub3D maps/bad/empty.cub
    ```

- **File name ends with a letter**
    ```sh
    ./cub3D maps/bad/file_letter_end.cub
    ```

- **Forbidden file**
    ```sh
    ./cub3D maps/bad/forbidden.cub
    ```

- **Map appears at the beginning of the file**
    ```sh
    ./cub3D maps/bad/map_first.cub
    ```

- **Map appears in the middle of the file**
    ```sh
    ./cub3D maps/bad/map_middle.cub
    ```

- **Missing map section**
    ```sh
    ./cub3D maps/bad/map_missing.cub
    ```

- **File contains only the map**
    ```sh
    ./cub3D maps/bad/map_only.cub
    ```

- **Multiple players in the map**
    ```sh
    ./cub3D maps/bad/player_multiple.cub
    ```

- **No player in the map**
    ```sh
    ./cub3D maps/bad/player_none.cub
    ```

- **Player positioned on the edge of the map**
    ```sh
    ./cub3D maps/bad/player_on_edge.cub
    ```

- **Texture path is a directory**
    ```sh
    ./cub3D maps/bad/textures_dir.cub
    ```

- **Duplicate texture definitions**
    ```sh
    ./cub3D maps/bad/textures_duplicates.cub
    ```

- **Forbidden texture file**
    ```sh
    ./cub3D maps/bad/textures_forbidden.cub
    ```

- **Invalid texture file**
    ```sh
    ./cub3D maps/bad/textures_invalid.cub
    ```

- **Missing texture definition**
    ```sh
    ./cub3D maps/bad/textures_missing.cub
    ```

- **No texture information**
    ```sh
    ./cub3D maps/bad/textures_none.cub
    ```

- **Texture file is not in XPM format**
    ```sh
    ./cub3D maps/bad/textures_not_xpm.cub
    ```

- **Hole in the east wall**
    ```sh
    ./cub3D maps/bad/wall_hole_east.cub
    ```

- **Hole in the north wall**
    ```sh
    ./cub3D maps/bad/wall_hole_north.cub
    ```
