#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread> 
#include <chrono>
#include <string>

using namespace std::chrono_literals;
using namespace std;

HANDLE console;


void Draw() {
    COORD pos;
    pos.X = 70;
    pos.Y = 10;

    SetConsoleTextAttribute(console, BACKGROUND_BLUE);

    for (int i = 0; i < 30; ++i) {
        SetConsoleCursorPosition(console, pos);
        std::cout << " ";
        pos.X++;
    }
}


void Write() {
    COORD pos;
    pos.X = 70;
    pos.Y = 10;
    SetConsoleCursorPosition(console, pos);
    int input = 0;
    while (input != 27)
    {
        if (_kbhit())
        {
            input = _getch();
            if ((input == 224 || input == 0) && _kbhit() == 1) {
                switch (_getch()) {
                case 75:
                    if (pos.X > 70) {
                        pos.X--;
                    }
                    SetConsoleCursorPosition(console, pos);
                    break;
                case 77:
                    if (pos.X < 99) {
                        pos.X++;
                    }
                    SetConsoleCursorPosition(console, pos);
                    break;
                }
            }
            else {
                if ((pos.X >= 70 && pos.X <= 99) && (32 <= input && input <= 255)) {
                    cout << char(input);
                    pos.X++;
                    SetConsoleCursorPosition(console, pos);
                }
                if ((pos.X > 70 && pos.X <= 100) && input == 8) {
                    pos.X--;
                    SetConsoleCursorPosition(console, pos);
                    cout << " ";
                    SetConsoleCursorPosition(console, pos);
                }
            }
        }
    }
}

int main() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw();
    Write();
}
