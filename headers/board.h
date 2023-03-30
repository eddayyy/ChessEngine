#pragma once
#include <SDL.h>
#include <pieces.h>
#include <iostream>
#include <vector>

class Board
{
public:
    // Constructors, assignments, and destructor
    Board();
    ~Board();

    // Accessors
    int         boardSize()    const noexcept;
    int         squareSize()   const noexcept;
    SDL_Window* window()       const noexcept;

    // Public methods
    int  SDLinit();
    int  renderBoard();
    void loadPieceImages();

private:
    int _BOARD_SIZE  =  8;   // Cells
    int _SQUARE_SIZE = 100; // Pixels

    ChessPiece _board[8][8]; 

    SDL_Window*     _window;
    SDL_Renderer*   _renderer;
};
