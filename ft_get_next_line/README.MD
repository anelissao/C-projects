# get_next_line

This project implements the `get_next_line` function in C, which allows reading text line by line from a file descriptor, including the standard input. 

## Overview

The `get_next_line` function reads text line by line from a file descriptor, allowing you to process text files efficiently without loading the entire file into memory.

## Project Description

- The function returns the line that has just been read. If there is nothing else to read or if an error has occurred, it returns `NULL`.
- The project includes both the main implementation file `get_next_line.c` and utility functions in `get_next_line_utils.c`.
- It also provides a bonus implementation `get_next_line_bonus.c` for additional features and `get_next_line_utils_bonus.c` for utility functions related to the bonus.
- The header file `get_next_line.h` contains the prototype of the `get_next_line` function.

## Usage

To use `get_next_line` in your project, include the header file `get_next_line.h` and compile your program with the required flags and source files:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx <files>.c

## Project Structure

- `get_next_line.c`: Main implementation of the `get_next_line` function.
- `get_next_line_utils.c`: Utility functions needed for `get_next_line` to work.
- `get_next_line_bonus.c`: Bonus implementation of `get_next_line` with additional features.
- `get_next_line_utils_bonus.c`: Utility functions for the bonus implementation.
- `get_next_line.h`: Header file containing the prototype of the `get_next_line` function.

## Disclaimer

This README provides an overview of the `get_next_line` project and its usage. It's essential to thoroughly understand the project specifications and adhere to them while using or modifying the code.

