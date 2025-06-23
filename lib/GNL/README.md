<p align="center">
  <img src="https://github.com/Ailton-Bezerra/Ailton-Bezerra/blob/main/badges/get_next_linem.png" alt="gnl 42 project badge"/>
<p align="center">
$${\color{lightgreen}125/100}$$ 🌟

## Description
`get_next_line` is a C function that reads text from a file descriptor (fd) one line at a time.
- The project's key innovation is the use of a static variable. This optimized version implements a linked list with a tail pointer for enhanced performance.

## Example usage

Here is a simple example of how to use `get_next_line` to read a file line by line:

```c
#include <fcntl.h>  // open
#include <stdio.h>  // printf
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

- example.txt content:
```txt
CopiHello, world!
This is a test file.
get_next_line is working!
```

Output:
```bash
Hello, world!
This is a test file.
get_next_line is working!
```
---
## Contact Information
For any questions or suggestions, feel free to reach out to me via my [GitHub profile](https://github.com/Ailton-Bezerra).
