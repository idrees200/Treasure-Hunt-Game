# Treasure Hunt Game

This C++ program simulates a text-based treasure hunt game set within a haunted house. Players navigate through various rooms, encountering different challenges and collecting treasures while avoiding dangers. The game utilizes file input to dynamically load room configurations.

## Features

- **Multiple Rooms**: The game consists of multiple rooms, each with its own layout loaded from external text files (`room1.txt`, `room2.txt`, etc.).
  
- **Interactive Gameplay**: Players can move up, down, left, or right within each room using arrow keys. Movements reveal tiles containing characters representing different elements of the game world (player, treasure, devil, gasper, portal).

- **Dynamic Room Switching**: Portals found within rooms teleport the player to another randomly selected room, adding unpredictability to gameplay.

- **Character Encounters**: Players may encounter characters such as the Devil (D) or Gasper (G), each triggering specific game events upon interaction.

- **Treasure Collection**: Finding the treasure (T) in any room triggers a game completion message and displays the path traveled by the player.

- **Path Tracking**: The game tracks and displays the path traveled by the player using a stack data structure, showing visited coordinates in each room.

## Implementation

The program is implemented in C++ and includes the following classes:

- **Stack**: Manages the player's movement history using a stack to store coordinates.
  
- **Room**: Represents each room in the game, handling room loading, player movements, character encounters, and path tracking.

- **Main Program**: Controls the game loop, user input handling, room switching, and termination conditions.

## How to Run

To run the game:

1. Compile the `main.cpp` file using a C++ compiler (e.g., g++ on Linux or MinGW on Windows).
   ![image](https://github.com/idrees200/Treasure-Hunt-Game/assets/113856749/b23e39ef-84ba-43a7-8ead-182ef8c4a69d)
   ![image](https://github.com/idrees200/Treasure-Hunt-Game/assets/113856749/1925435d-d34a-4894-bedc-6a0bc2677bde)
   ![image](https://github.com/idrees200/Treasure-Hunt-Game/assets/113856749/6f431f71-5e6d-440e-b4a5-c7caddd31e97)
   ![image](https://github.com/idrees200/Treasure-Hunt-Game/assets/113856749/dc7c5b47-ace2-486c-a7bb-b7da64ed9698)




