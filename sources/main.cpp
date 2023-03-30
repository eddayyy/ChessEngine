//============================================================
// FILE: main.cpp
//============================================================
#include <SDL.h>
#include <board.h>
#include <iostream>

int main(int argc, char* argv[]) {
    Board drawBoard;
    drawBoard.renderBoard();
    return 0;
}
