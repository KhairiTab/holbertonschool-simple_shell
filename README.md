# Holberton Simple Shell 



![Alt text](https://media.geeksforgeeks.org/wp-content/uploads/20190502161414/Screenshot-from-2019-05-02-16-04-50.png)


## Description
The Holberton Simple Shell is a basic Unix command-line interpreter developed as a project for Holberton School.
It provides users with the ability to execute commands, manage processes, and navigate the file system.
![Alt text](https://miro.medium.com/v2/resize:fit:1400/0*-OOMpchdZWQZr4zw)

## Getting Started

### Prerequisites
- Ubuntu 20.04 LTS
- GCC (GNU Compiler Collection)

### Compilation
To compile the Holberton Simple Shell, use the following command in your terminal:
```shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage
Interactive Mode
Run the shell in interactive mode by executing the compiled binary:
----------------------------------
$ ./hsh
($) /bin/ls
file1.txt  file2.txt  directory/
($)
($) exit
$
--------------------------------
Non-Interactive Mode
You can also run commands in non-interactive mode by piping input to the shell:
--------------------------------
$ echo "/bin/ls" | ./hsh
file1.txt  file2.txt  directory/
$
--------------------------------

** Features :

° Display a command prompt and wait for user input.
° Execute simple commands with or without arguments.
° Handle Ctrl+D for the end-of-file condition.
° Implement basic error handling and display error messages.

** Built-in Commands :

The Holberton Simple Shell supports the following built-in commands:

° exit: Exit the shell.
° env: Print the current environment variables.

Examples : 

1- Run a command in interactive mode: 
--------
$ ./hsh
($) echo "Hello, World!"
Hello, World!
($)
-------

2-Execute a command with arguments:
----------
$ ./hsh
($) ls -l
total 12
-rw-rw-r-- 1 user user   0 Aug 18 12:00 file1.txt
-rw-rw-r-- 1 user user   0 Aug 18 12:00 file2.txt
drwxrwxr-x 2 user user 4096 Aug 18 12:00 directory/
($)
----------

Contributor : 
Khaled Jallouli (jallouli.khaled.2001@gmail.com)
Khaireddine Taboubi (taboubikhairi68@gmail.com)

License :
This project is licensed under the MIT License - see the LICENSE file for details.

