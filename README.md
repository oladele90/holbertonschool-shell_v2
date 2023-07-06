MAN PAGE: SHELL PROJECT (1)

NAME
shell-project - a shell project for learning shell programming and understanding how shells work.

SYNOPSIS
This is my own implementation of the Unix Shell. It is able to execute built-in commands [cd, cd -, cd /path/to/directory, exit, env] and also library functions as long as the path is provided.

DESCRIPTION
The shell project is designed to provide a hands-on learning experience in shell programming and to deepen understanding of how shells function within an operating system environment. This project explores various concepts related to shell programming, process management, and system calls.

LEARNING OBJECTIVES
By completing this shell project, learners are expected to gain knowledge and understanding of the following concepts:

The design and implementation of the original Unix operating system
The author of the first version of the UNIX shell
The inventor of the B programming language (the direct predecessor to the C programming language)
Ken Thompson and his contributions to the field
How a shell works and its role in the operating system
The concepts of pid (process ID) and ppid (parent process ID)
Manipulating the environment of the current process
The difference between a function and a system call
Creating processes and understanding their life cycle
The three prototypes of the main function
How the shell uses the PATH environment variable to find programs
Executing another program with the execve system call
Suspending the execution of a process until one of its children terminates
Understanding the concept of EOF (end-of-file)
Redirecting the content of a file into another file
The concept of a pipeline and how it connects multiple processes together
Setting up a pipe for inter-process communication
REQUIREMENTS
The following requirements must be met for the successful completion of the shell project:

Allowed editors: vi, vim, emacs
All files will be compiled on Ubuntu 14.04 LTS
C programs and functions should be compiled with gcc 4.8.4
Code should follow the Betty style, checked using betty-style.pl and betty-doc.pl
EXAMPLES
Here are some example commands that can be used with the shell project:

Run the shell project:
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
SEE ALSO
The Unix operating system documentation.
AUTHOR
Written by OLADELE MIRO