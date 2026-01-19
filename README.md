***

# consha

consha is a simple command-line interpreter (shell), developed as a custom implementation of the 42 school's minishell project. The goal of this software is to emulate bash behavior, managing processes, file descriptors, and environment manipulation.

## Features

consha supports a variety of features found in modern shells, including:

*   **Logical Operators:** Support for conditional execution with `&&` (AND) and `||` (OR).
     
*   **Subshells:** Ability to group commands and execute them in a child process using parentheses.
    *   Example: `(cd folder && pwd) && pwd`

*   **Wildcards:** Expansion of the `*` character in the current directory. The system supports matching by:
    *   Prefix (e.g., `ab*`)
    *   Suffix (e.g., `*yz`)
    *   Combination of both (e.g., `a*z`)
*   **Quotes and Escapes:**
    *   Single quotes (`'`) prevent interpretation of meta-characters.
    *   Double quotes (`"`) allow variable expansion but inhibit other meta-characters.
    *   Backslash (`\`) acts as an escape character for literals.
*   **Environment Variables:**
    *   Variable expansion with `$VAR`.
    *   Variable creation and export.
    *   Variable removal.
*   **Special Variables:**
    *   `$?`: Returns the exit status of the last executed command.
    *   `$$`: Returns the process ID (PID) of the current shell.
*   **Builtins:** Custom implementation of the following internal commands:
    *   `echo`
    *   `cd`
    *   `pwd`
    *   `export`
    *   `unset`
    *   `env`
    *   `exit`

## Build and Installation Instructions

This project uses CMake as its build system. Follow the steps below to compile and install the shell on your system.

### Prerequisites

*   C Compiler (GCC or Clang)
*   CMake
*   Make

### Build Process

1.  In the project root directory, create a directory for the build files and navigate into it:

    ```bash
    mkdir build
    cd build
    ```

2.  Generate the build system files with CMake:

    ```bash
    cmake ..
    ```

3.  Compile the executable:

    ```bash
    make
    ```

After this step, the `consha` binary will be available inside the `build` folder.

### System Installation

To install the shell system-wide (making it accessible from any location), use the install command. Depending on your system configuration, superuser privileges (root) may be required:

```bash
sudo make install
```

This will copy the binary to the default installation directory (usually `/usr/local/bin` or `/usr/bin`), allowing you to launch the shell simply by typing `consha` in your current terminal.

## Usage

To start the shell after local compilation:

```bash
./consha
```

Or, if you performed the system installation:

```bash
consha
```

To exit the shell, use the `exit` command or press `Ctrl+D` (if the command line is empty).
