#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawPaddle(int x, int y) {
    gotoxy(x, y);
    printf("|");
    gotoxy(x, y + 1);
    printf("|");
    gotoxy(x, y + 2);
    printf("|");
    gotoxy(x, y + 3);
    printf("|");
}

void drawBall(int x, int y) {
    gotoxy(x, y);
    printf("O");
}

int main() {
    int paddleY = 10;
    int ballX = 5, ballY = 5;
    int ballSpeedX = 1, ballSpeedY = 1;

    while (1) {
        system("cls"); // Clear the screen

        drawPaddle(1, paddleY);
        drawBall(ballX, ballY);

        // Move the ball
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        // Bounce off walls
        if (ballX <= 0 || ballX >= 79) {
            ballSpeedX = -ballSpeedX;
        }

        if (ballY <= 0 || ballY >= 23) {
            ballSpeedY = -ballSpeedY;
        }

        // Check paddle collision
        if (ballX == 2 && ballY >= paddleY && ballY <= paddleY + 3) {
            ballSpeedX = -ballSpeedX;
        }

        // Input for paddle movement
        if (GetAsyncKeyState(VK_UP) & 0x8000 && paddleY > 0) {
            paddleY--;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 && paddleY < 20) {
            paddleY++;
        }

        Sleep(50); // Pause for a short time to control game speed
    }

    return 0;
}
