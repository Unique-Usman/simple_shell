# Simple Shell

The Simple Shell is a basic implementation of a command-line shell, also known as a command-line interpreter or command-line interface (CLI). It provides users with a simple and intuitive way to interact with their computer's operating system by executing various commands.

## Features

- **Command Execution**: Users can enter commands, and the shell will execute them as if they were executed directly in the terminal.

- **Built-in Commands**: The shell supports basic built-in commands, such as `cd` (change directory) and `exit` (terminate the shell).

- **Error Handling**: Graceful handling of errors with informative error messages when a command is not found or fails to execute.

- **Signal Handling**: Proper capture and handling of signals to ensure the termination and cleanup of processes.

- **Input/Output Redirection**: The shell supports input/output redirection using the `>` and `<` operators, allowing users to redirect command output to files or read input from files.

- **Pipeline Commands**: Users can chain multiple commands together using the `|` operator, enabling the output of one command to be used as input for another.

## Getting Started

1. Clone this repository to your local machine using the following command:
git clone <repository_url>


2. Compile the source code to create the shell executable:

gcc -o simple_shell main.c shell.c

3. Run the shell executable:


4. The shell prompt should now appear, indicating that the shell is ready to accept commands.

## Usage

Once the shell is running, you can enter commands just like you would in a regular terminal. For example:

$ ls
file1.txt file2.txt folder1 folder2
$ cd folder1
$ pwd
/home/uniqueusman/folder1
$ cat file1.txt
This is the content of file1.
$ echo "Hello, World!" > greetings.txt
$ cat greetings.txt
Hello, World!
$ ls | grep txt
file1.txt
greetings.txt


To exit the shell, simply type `exit`:

$ exit
Goodbye!

## Acknowledgments

- This project draws inspiration from the simplicity and functionality of Unix-based shells.
- This project is a pair C-program project from a ALXSE program.
- Special thanks to ALX, Julien Barbier, Fred Swaniker and Maarten van Middelaar and other mentors
---

_**Note**: The Simple Shell is designed for educational purposes and may not include advanced features or security mechanisms found in mature shells intended for production environments._

##Authors of the Project 
1. Christian Aziba
- https://www.linkedin.com/in/christianaziba/
2. Usman Akinyemi
- https://twitter.com/usman_akinyemi
