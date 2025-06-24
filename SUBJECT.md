## Map Parsing and Validation Checklist

- [ ] **File Extension:** Map file must have a `.cub` extension.
- [ ] **Allowed Characters:** Map can only contain the following characters:
    - `0` — empty space
    - `1` — wall
    - `N`, `S`, `E`, `W` — player start positions (North, South, East, West)
- [ ] **Map Closure:** The map must be fully enclosed/surrounded by walls.
- [ ] **Element Separation:** Each type of element can be separated by one or more empty lines.
- [ ] **Map Position:** The map content must always appear at the end of the file.
- [ ] **Element Identification:** Except for the map, each element must begin with its type identifier.

> **Note:** Any misconfiguration must cause the program to exit and return `"Error\n"`.
