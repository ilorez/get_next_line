# Get Next Line (GNL)

This repository contains an implementation of the **get_next_line** project from the 42 curriculum. The objective of this project is to create a function that reads and returns one line at a time from a given file descriptor.

## Table of Contents
- [Introduction](#introduction)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Function Descriptions](#function-descriptions)
- [Usage](#usage)
- [Notes](#notes)

## Introduction
The **get_next_line** function reads a line from a file descriptor (FD) until it encounters a newline character (`\n`) or reaches the end of the file (EOF). The project adheres to specific rules and constraints, such as handling errors gracefully and maintaining efficiency.

## Mandatory Part
The mandatory implementation of **get_next_line** includes:
- Reading from a single file descriptor.
- Handling buffer sizes defined by the macro `BUFFER_SIZE`.
- Ensuring that the function returns `NULL` for errors, empty files, or when reaching EOF.

### Function Signature
```c
char *get_next_line(int fd);
```

## Bonus Part
The bonus part expands on the mandatory functionality by:
- Supporting multiple file descriptors simultaneously.

### Function Signature
```c
char *get_next_line(int fd);
```

This implementation uses an array to store static variables for each file descriptor (up to `OPEN_MAX` FDs).

## Function Descriptions
### Mandatory Functions
#### `_cut_line`
Extracts the current line from the cached data and updates the cache.
- **Parameters**:
  - `c_point`: Pointer to the cached data.
  - `line`: Pointer to store the extracted line.
- **Behavior**: Frees the cache if it becomes empty.

#### `_search_for_line`
Reads from the file descriptor until it finds a newline character or reaches EOF.
- **Parameters**:
  - `fd`: File descriptor to read from.
  - `c_point`: Current cached data.
  - `buffer`: Temporary buffer for reading.
- **Return Value**: Updated cache or `NULL` on failure.

#### `get_next_line`
Combines the above two functions to implement the complete behavior of reading a line.
- **Parameters**:
  - `fd`: File descriptor to read from.
- **Return Value**: Line read from the file or `NULL` for errors or EOF.

### Bonus Functions
The bonus functions behave similarly to the mandatory ones but manage separate caches for multiple file descriptors using a static array of pointers.

## Usage
### Compilation
To compile the project, include all necessary `.c` files and define the `BUFFER_SIZE` macro. For example:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

### Running the Function
- Include the header file `get_next_line.h` in your code.
- Call `get_next_line` in a loop to read lines from a file descriptor.

Example:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0) return 1;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Notes
1. **Buffer Size**: The `BUFFER_SIZE` macro affects performance and memory usage. Test with different sizes for optimal results.
2. **Error Handling**: The function gracefully handles errors, such as invalid file descriptors or memory allocation failures.
3. **Static Variables**: Static variables are used to maintain data between successive calls to `get_next_line`.
4. **Memory Management**: Ensure to free the returned lines to avoid memory leaks.


