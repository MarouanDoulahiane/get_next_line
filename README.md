# get_next_line

## About
The `get_next_line` project tackles the challenge of efficiently reading lines from a file descriptor in C. By implementing this function, you gain insights into file handling operations in an operating system and how programming languages interpret and process file data. This skill is fundamental for any programmer dealing with file management and data persistence tasks. The project's main objective is to develop a function that reads and returns one line at a time from a text file.

For more detailed information, refer to the [subject of this project](https://github.com/Surfi89/42cursus/blob/main/Subject%20PDFs/01_get_next_line_en.pdf).

## Usage

### Requirements
To compile and use the function, ensure you have the following:
- `gcc` compiler
- Standard C libraries

### Instructions

1. **Using it in your code:**

Include the function's header file:
```c
#include "get_next_line.h"
```

During compilation, add the source files and the required flag:
```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c
```

## Testing

To test the `get_next_line` function, follow these steps:

1. **Edit the `get_next_line.c` file:**

Uncomment the main function and relevant headers inside it.

2. **Edit the `test.txt` files (if necessary):**

Modify the text content to test different scenarios.

3. **Compile and run the program:**

Replace `<xx>` with your desired buffer size.
```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<xx> get_next_line.c get_next_line_utils.c && ./a.out
```

Alternatively, you can use third-party testers like [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester) for comprehensive testing.
