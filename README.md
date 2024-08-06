## Overview
- This is a generic data structure in C with an interactive terminal menu
- It allows you to manage student data, including functionalities to insert, remove, find, list, empty, and destroy student records

<p>This project was developed during my Data Structures I course in college.

## Features
- **Insert Student**: Adds a new student with name, ID, and grade
- **Remove Student**: Removes a specific student
- **Find Student**: Searches for a student by name
- **List Students**: Lists all stored students
- **Empty Structure**: Removes all students from the structure
- **Destroy Structure**: Frees all memory allocated by the structure

## Project Structure
- **gcofo.h**: Header file containing function prototypes
- **gcofo.c**: Implementation of the functions defined in gcofo.h
- **prog.c**: Main program utilizing the data structure functions with an interactive menu

## Installation and Usage
To compile and run this project, follow these steps:
1. Install GCC
2. Clone the repository:
   ```bash
   git clone https://github.com/GiuliaFreulon/generic-data-structure
   cd generic-data-structure
3. Compile the program:
   ```bash
   gcc -o my_program prog.c gcofo.c
4. Run the program:
   ```bash
   ./my_program
