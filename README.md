# Grocery Store Management System

This is a C-based Grocery Store Management System. The system allows users to log in, create an account, view available grocery items, search for specific items, and generate a bill for purchased items.

## Features

- **User Authentication**: Allows users to log in or create a new account.
- **Display Items**: Shows a list of available grocery items categorized and aligned properly.
- **Search Items**: Allows users to search for specific items by name.
- **Generate Bill**: Calculates the total cost of selected items and applies discounts if applicable.

## Files in the Project

1. `make.c` - The main file which coordinates the execution of the program.
2. `login.c` - Handles user login and account creation functionalities.
3. `items.c` - Manages item display and search functionalities.
4. `bill.c` - Manages bill generation functionalities.
5. `users.txt` - Stores user login information (username and password).

## How to Compile and Run

### Prerequisites

- GCC compiler

### Compilation

To compile the project, run the following command in your terminal:

```sh
gcc make.c login.c items.c bill.c -o store
