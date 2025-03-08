#include <iostream>
#include <conio.h>    // For _kbhit() and _getch() to read keyboard input
#include <windows.h>  // For Sleep() to control game speed

using namespace std;

bool gameOver;
const int width = 20;  // Game board width
const int height = 20; // Game board height
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];  // Snake tail coordinates
int nTail;                   // Current length of the snake tail
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;  // Initial snake head position
    y = height / 2;
    fruitX = rand() % width;   // Random food position
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls");  // Clear the screen
    
    // Draw the top wall
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Draw the game board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";  // Left wall

            if (i == y && j == x)
                cout << "O";  // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "F";  // Food
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";  // Snake tail
                        printTail = true;
                    }
                }
                if (!printTail) cout << " ";  // Empty space
            }

            if (j == width - 1) cout << "#";  // Right wall
        }
        cout << endl;
    }

    // Draw the bottom wall
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Display the score
    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;  // Press 'x' to quit
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    // Move the tail
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move the snake head
    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default: break;
    }

    // Collision with the walls (game over)
    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    // Collision with the snake itself (game over)
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Snake eats food
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;   // Place new food at a random position
        fruitY = rand() % height;
        nTail++;  // Grow the snake
    }
}

int main() {
    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);  // Sleep for 100ms to control the game speed
    }

    cout << "Game Over!" << endl;
    return 0;
}
