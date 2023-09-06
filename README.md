# Simple Shell

This is a simple UNIX command line interpreter created as part of a school project. The project is divided into several versions, each building on the previous one to add more functionality.

## Tasks

### Task 0 - Betty Would Be Proud

- Write a beautiful code that passes the Betty checks.

### Task 1 - Simple Shell 0.1

- Write a UNIX command line interpreter.
- Usage: `simple_shell`
- Your Shell should:
  - Display a prompt and wait for the user to type a command. A command line always ends with a new line.
  - The prompt is displayed again each time a command has been executed.
  - The command lines are simple, no semicolons, no pipes, no redirections, or any other advanced features.
  - The command lines are made only of one word. No arguments will be passed to programs.
  - If an executable cannot be found, print an error message and display the prompt again.
  - Handle errors, including "end of file" condition (Ctrl+D).

### Task 2 - Simple Shell 0.2

- Simple shell 0.1 plus:
- Handle command lines with arguments.

### Task 3 - Simple Shell 0.3

- Simple shell 0.2 plus:
- Handle the PATH.
- Fork must not be called if the command doesn't exist.

### Task 4 - Simple Shell 0.4

- Simple shell 0.3 plus:
- Implement the exit built-in, which exits the shell.

### Task 5 - Simple Shell 1.0

- Simple shell 0.4 plus:
- Implement the env built-in, which prints the current environment.

## Usage

To compile and run the simple shell, use the following commands:

~bash
~gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./simple_shell


## Authors

- [ElmourikiYassine]
- [Moamenmuh13]

## GitHub Repository