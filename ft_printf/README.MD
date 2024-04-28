# ft_printf

## Summary

The `ft_printf` project involves recoding the libc’s printf function. Your function, `ft_printf`, will be prototyped similarly to printf. You won't handle buffer management within the function. The project requires you to manage various conversions, flags, minimum field-width, precision, and different length modifiers.

## Features

- The `ft_printf` function is prototyped similarly to `printf`.
- Conversions managed: `s`, `S`, `p`, `d`, `D`, `i`, `o`, `O`, `u`, `U`, `x`, `X`, `c`, `C`.
- Managed special case `%%` to print a single `%`.
- Managed flags `#`, `0`, `-`, `+`, and space.
- Minimum field-width is handled.
- Precision is handled.
- Supported length modifiers: `hh`, `h`, `l`, `ll`, `j`, `z`.

## Usage

To compile the project, run the provided Makefile:

```bash
make
```

This will compile your project and create the `libftprintf.a` library.

To use `ft_printf` in your C code, include the header file:

```c
#include "ft_printf.h"
```

Then, call the function similarly to `printf`:

```c
ft_printf("Format string", arguments);
```

## Example

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s!\n", "world");
    return 0;
}
```

## Authors

Anouar Elissaoui

## Acknowledgments

This project was completed as part of the curriculum at 1337-School(42-Network).

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
