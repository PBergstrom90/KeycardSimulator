# Keycard System

## Overview

This program simulates a basic keycard system where users can manage a list of keycards, grant or revoke access, and save/load keycard data to/from a text file.

## Features

- **Add New Keycards:**
  Users can add new keycards to the system, specifying unique card IDs and access permissions.

- **Revoke Access:**
  The program allows users to revoke access for specific keycards. This feature is crucial for maintaining security and controlling entry permissions.

- **View Keycard List:**
  Users can view the list of keycards in the system. This provides an overview of all registered keycards and their current access status.

- **Save and Load Keycard Data:**
  The system supports saving keycard data to a file (`cardlist.txt`) and loading data from the same file. This ensures persistent storage of keycard information between program sessions.

- **Simulate Remote Door Operations:**
  The program includes a simulation of remote door operations. Users can initiate door actions such as opening or locking, providing a visual representation through simulated green and red lights.

- **Scan Keycards:**
  Users can scan a keycard, check its access permissions, and simulate corresponding door actions based on the card's status (access granted or denied).

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

- `main.c`: Main program file.
- `adminmenu.c`: Admin menu functions.
- `card.h`: Keycard-related struct.
- `cardlist.h`: Struct for managing the list of keycards.
- `fileio.c`: File I/O functions for saving and loading keycard data.
- `listcard.c`: Functions for listing and printing card information.
- `cardaccess.c`: Functions responsible for handling card access and modifying access permissions.
- `remotedoor.c`: File simulating remote door operations, with a red-green light simulation.
- `scancard.c`: Functions responsible for scanning a card, checking access permissions, and simulating door actions.
- `safeinput.c`: Functions for handling user inputs throughout the program.

## Sample Keycards (Default)

- Card ID: 1212, Access Granted: Yes
- Card ID: 1213, Access Granted: No

## File Descriptions

- `cardlist.txt`: Text file to save/load keycard data. Is created upon program start, if it has not yet been created.
