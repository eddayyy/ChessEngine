//============================================================
// FILE: board.h
//============================================================
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
    void initializeBoard();

private:
    // Private members
    int _BOARD_SIZE  = 8;                           // Number of cells in the board
    int _SQUARE_SIZE = 100;                         // Size of each cell in pixels

    // ChessPiece struct
    struct ChessPiece {
        ChessPieceImage::type  Piece;               // Type of chess piece
        ChessPieceImage::color Team;                // Color of the chess piece
        std::shared_ptr<ChessPieceImage> pieceObj;  // Shared pointer to the ChessPieceImage object

        ChessPiece() = default;                     // Default constructor

        // Parametrized constructor
        ChessPiece(ChessPieceImage::type pieceType, ChessPieceImage::color pieceColor, SDL_Renderer* renderer)
            : Piece(pieceType), Team(pieceColor), pieceObj(std::make_shared<ChessPieceImage>(renderer, pieceType, pieceColor)) {}
    };

    ChessPiece _board[8][8];                        // 8x8 chess board

    SDL_Window* _window;                            // Pointer to the SDL_Window object
    SDL_Renderer* _renderer;                        // Pointer to the SDL_Renderer object
};
