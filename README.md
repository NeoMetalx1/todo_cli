# todo_cli

`todo_cli` is a simple command-line interface (CLI) application written in C++ for managing a to-do list. It allows users to add, view, and manage their tasks directly from the terminal.

## Features

- **Add Tasks**: Quickly add new tasks to your to-do list.
- **View Tasks**: Display all your pending tasks in the terminal.
- **Delete Tasks**: Remove tasks that are no longer needed.

## Installation

To build and install `todo_cli` on your system, follow these steps:

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/NeoMetalx1/todo_cli.git
   ```

2. **Navigate to the Project Directory**:

   ```bash
   cd todo_cli
   ```

3. **Create vault dir**:

   ```bash
   mkdir vault
   ```

3. **Build the Application**:

   Use the provided `Makefile` to compile the project:

   ```bash
   make
   ```

   This will generate an executable named `todo_cli` in the project directory.

## Usage

After building the application, you can start using `todo_cli` to manage your tasks.

   ```bash
   ./todo
   ```

## Flags

- **Help menu**:

  ```bash
  ./todo -h
  ```

- **Create a Task**:

  ```bash
  ./todo -c 'Your task name here'
  ```

- **View All Tasks**:

  ```bash
  ./todo -s
  ```

- **View Specified Task**:

  ```bash
  ./todo -s 'Your task name here'
  ```

- **Delete a Task**:

  ```bash
  ./todo -d 'Your task name here'
  ```



