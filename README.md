# Keycard System

## Overview

This program simulates a basic keycard system where users can manage a list of keycards, grant or revoke access, and save/load keycard data to/from a text file.

## Features

- Add new keycards
- Revoke access for specific keycards
- View the list of keycards
- Save keycard data to a file
- Load keycard data from a file

## Getting Started

1. **Compilation:**
   - Make sure you have a C compiler installed.
   - Compile the program using your preferred compiler. Example: `gcc main.c -o keycard_system`

2. **Run the Program:**
   - Execute the compiled program: `./keycard_system`

3. **Usage:**
   - Follow the on-screen instructions to navigate through the keycard system.
   - Use the admin menu to manage keycards.

## File Structure

- `main.c`: Main program file
- `adminmenu.c`: Admin menu functions
- `card.c`: Keycard-related functions
- `cardlist.c`: Functions for managing the list of keycards
- `fileio.c`: File I/O functions for saving and loading keycard data

## Sample Keycards (Default)

- Card ID: 1212, Access Granted: Yes
- Card ID: 1213, Access Granted: No

## File Descriptions

- `cardlist.txt`: Text file to save/load keycard data
