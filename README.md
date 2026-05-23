# C Systems Test Lab

This repository is a personal lab for exploring how C interprets integers at a low level. This includes binary representation, unsigned interpretation, two's-complement, and edge cases with how C may represent some values.

## Current Features

So far, this repository offers:
- Validating a binary string in the CLI (which is then validated). The CLI will report:
    - Its width
    - Its unsigned representation
    - Its signed representation (calculated using two's complement)
    - The minimum signed value of its width
    - The maximum signed value of its width
    - The maximum unsigned value of its width
- Unit tests

## How to Build

### Dependencies

To build this, you will need the following dependencies:

- `make` tool for building the project
- GCC compiler that supports the C11 standard
- A Unix-like system, such as Linux.

### Clone the Repository

Navigate to where you want to clone the repository and run:

```
git clone https://github.com/Syntax-Sculptor/c-systems-test-lab.git
```

### Creating the Binaries

To create the needed binaries, simply run `make`. By default, it will create `systems_test_lab` in `build/`.

If you wish to run the unit tests, then run `make test`, which will test the program's functionality using the testing library, Unity.

## Usage

The program only takes one argument, that being a binary string that is between 1 and 32 bits:

```
./build/systems_test_lab 1010
Bits:       1010
Width:      4
Unsigned:   10
Signed:     -6
TMin:       -8
TMax:       7
UMax:       15
```

The program will only accept binary strings of a valid width, any other input will be rejected.

## Contribution Guidelines

As this is a solo project to test my own skills and understanding, I am not accepting any pull requests or contributions. However, you are free to create any issues and I will gladly look at them.

## Special Thanks

Special thanks to the kind folks behind ThrowTheSwitch and contributors for [Unity](https://github.com/ThrowTheSwitch/Unity), which was used to implement the unit tests for this lab.