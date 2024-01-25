#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ROWS 10
#define COLS 15

int playerX, playerY;
int exitX, exitY;

char maze[ROWS][COLS] = {
    "###############",
    "#S#...........#",
    "#.#.#########.#",
    "#.#.#.......#.#",
    "#.#.#.#####.#.#",
    "#...#.#...#.#.#",
    "#.###.#.#.#.#.#",
    "#.....#...#...#",
    "#.###########.#",
    "#E............#",
    "###############"
};

void printMaze() {
    system("cls");
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", maze[i]);
    }
}

void movePlayer(int x, int y) {
    maze[playerX][playerY] = '.'; // Clear current position
    playerX = x;
    playerY = y;
    maze[playerX][playerY] = 'P'; // Set new position
}

int main() {
    // Find the starting position and exit position
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                playerX = i;
                playerY = j;
            } else if (maze[i][j] == 'E') {
                exitX = i;
                exitY = j;
            }
        }
    }

    char move;
    while (1) {
        printMaze();

        if (playerX == exitX && playerY == exitY) {
            printf("\nCongratulations! You reached the exit!\n");
            break;
        }

        printf("\nUse 'W', 'A', 'S', 'D' to move (Q to quit): ");
        move = _getch();

        switch (move) {
            case 'W':
            case 'w':
                if (maze[playerX - 1][playerY] != '#') {
                    movePlayer(playerX - 1, playerY);
                }
                break;
            case 'A':
            case 'a':
                if (maze[playerX][playerY - 1] != '#') {
                    movePlayer(playerX, playerY - 1);
                }
                break;
            case 'S':
            case 's':
                if (maze[playerX + 1][playerY] != '#') {
                    movePlayer(playerX + 1, playerY);
                }
                break;
            case 'D':
            case 'd':
                if (maze[playerX][playerY + 1] != '#') {
                    movePlayer(playerX, playerY + 1);
                }
                break;
            case 'Q':
            case 'q':
                printf("\nGame terminated by user.\n");
                return 0;
        }
    }

    return 0;
}

