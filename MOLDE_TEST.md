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

- **Multiple extensions with an invalid ending**
    ```sh
    ./cub3d file.cub.cub.notcub
    ```
