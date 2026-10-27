# Binary Inspection Toolkit

A command-line tool written in C to explore how integers, data types, and binary operations work.

I built this project to get a better understanding of low-level programming in C, particularly binary representation, bitwise operations, and how data is stored in memory.

## Features

The toolkit currently includes seven modules:

- **Integer Inspector** — Displays a number in decimal, hexadecimal, octal, and binary, along with its sign, parity, and set and clear bits.
- **Binary Representation** — Prints the binary representation of an integer.
- **Bitwise Operations** — Performs AND, OR, XOR, NOT, left shift, and right shift operations.
- **Number System Converter** — Converts numbers between bases 2 and 36.
- **Data Type Explorer** — Displays the sizes and ranges of common C data types.
- **Memory Inspector** — Shows a variable's memory address, size, and byte representation.
- **Integer Overflow Explorer** — Checks whether adding two integers would exceed the range of a signed `int`.

 Requirements

- GCC or another compatible C compiler
- Make
- Linux or another environment with a compatible C toolchain

The project uses standard C library functions.

 Project Structure

```text
binary-inspection-toolkit/
├── include/
│   ├── binary_rep.h
│   ├── bitwise_ops.h
│   ├── data_type.h
│   ├── int_insp.h
│   ├── int_overflow.h
│   ├── memory_insp.h
│   ├── number_convert.h
│   └── toolkit_input.h
├── src/
│   ├── binary_rep.c
│   ├── bitwise_ops.c
│   ├── data_type.c
│   ├── int_insp.c
│   ├── int_overflow.c
│   ├── main.c
│   ├── memory_insp.c
│   ├── number_convert.c
│   └── toolkit_input.c
├── Makefile
└── README.md
```
 Getting Started

Clone the repository:

```bash
git clone https://github.com/YasH-cloud-cmd/binary_toolkit
cd binary-inspection-toolkit
```

Compile the project using the Makefile:

```bash
make
```

Run the program using the executable name configured in your Makefile. For example:

```bash
./bitinspect
```

If your Makefile uses a different executable name, replace `bitinspect` with that name.

 Usage

When you run the program, a menu appears with the available modules. Select an option to use the corresponding feature.

For example, the Bitwise Operations module accepts two integers and displays the results of bitwise operations. The Number System Converter lets you enter a number, specify its current base, and choose the base you want to convert it to.

The toolkit also checks input ranges in several modules to avoid invalid integer conversions and restricts shift counts to valid values for the type being used.

 What I Learned

While working on this project, I practised:

- Working with binary numbers and bitwise operators.
- Understanding integer ranges and data type sizes.
- Using pointers to inspect memory.
- Handling user input with `fgets()` and `strtoll()`.
- Organising a C program into separate source and header files.
- Using a Makefile to build a multi-file C project.

Future Improvements

Some things I may work on later:

- Adding automated tests.
- Improving the output formatting.
- Adding more memory and pointer experiments.
- Improving error handling and portability.

 License

No license has been added yet.
