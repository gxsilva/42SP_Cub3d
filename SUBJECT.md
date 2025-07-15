# Cub3d

## Map Parsing and Validation Checklist

- [X] **File Extension:** Map file must have a `.cub` extension.
- [X] **Allowed Characters:** Map can only contain the following characters:
    - `0` — empty space
    - `1` — wall
    - `N`, `S`, `E`, `W` — player start positions (North, South, East, West)
- [X] **Map Closure:** The map must be fully enclosed/surrounded by walls.
- [X] **Element Separation:** Each type of element can be separated by one or more empty lines.
- [X] **Map Position:** The map content must always appear at the end of the file.
- [X] **Element Identification:** Except for the map, each element must begin with its type identifier.
- [X] **Floor and Ceiling Colors:** The floor and ceiling must be set to two different colors.
> **Note:** Any misconfiguration must cause the program to exit and return `"Error\n"`.

## Program Interaction and Controls
The program displays the image in a window and adheres to the following rules:
- **Keyboard Controls:**
    - [X] The **left** and **right arrow keys** allow the player to look left and right within the maze.
    - [X] The **W**, **A**, **S**, and **D** keys enable movement through the maze from the player's point of view.
- **Exit Mechanisms:**
    - [X] Pressing the **ESC** key closes the window and exits the program cleanly.
    - [X] Clicking the **red cross** on the window's frame also closes the window and exits the program cleanly.
- **Graphics Library:**
    - [ ] The use of images from the **minilibX** library is strongly recommended for rendering.

> **Note:** The program must handle all interactions smoothly and without crashes.

### Valid Map Example

```text
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
1111111110110000011100001
1000000000110000011101111
1111011111111101110000001
1111011111111101110101001
1100000011010101110000001
1000000000000000110000001
1000000000000000110101001
1100000111010101111101111
1111011111101011011110101
1111111111111111111111111
```

**Legend:**
- `1`: Wall
- `0`: Empty space
- `N`: Player start position (North)

> All map rows are the same length and the map is fully enclosed by walls.
