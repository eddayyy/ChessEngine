#include "board.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
// Constructor
Board::Board()
{
    SDLinit();
    IMG_Init(IMG_INIT_PNG);
    _window = SDL_CreateWindow("Chess Engine",
             SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED,
             _BOARD_SIZE * _SQUARE_SIZE,
             _BOARD_SIZE * _SQUARE_SIZE,
             SDL_WINDOW_SHOWN);

    _renderer = SDL_CreateRenderer(_window, -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

// Destructor
Board::~Board()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

/*******************************************************************************
**  Accessors
*******************************************************************************/
int Board::boardSize() const noexcept
{
    return _BOARD_SIZE;
}

int Board::squareSize() const noexcept
{
    return _SQUARE_SIZE;
}

SDL_Window* Board::window() const noexcept
{
    return _window;
}


/*******************************************************************************
**  Public methods
*******************************************************************************/
int Board::SDLinit()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize!\nSDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}

int Board::renderBoard()
{
    initializeBoard();
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        SDL_RenderClear(_renderer);

        // Iterate through each square on the board
        for (int row = 0; row < _BOARD_SIZE; row++)
        {
            for (int col = 0; col < _BOARD_SIZE; col++)
            {
                if ((row + col) % 2 == 0)
                {
                    SDL_SetRenderDrawColor(_renderer, 240, 217, 181, 255); // Light squares
                }
                else
                {
                    SDL_SetRenderDrawColor(_renderer, 181, 136, 99, 255); // Dark square
                }
                SDL_Rect rect;                                          // Rectangle Struct: int x, y, width, height
                rect.x = col * _SQUARE_SIZE;
                rect.y = row * _SQUARE_SIZE;
                rect.w = _SQUARE_SIZE;
                rect.h = _SQUARE_SIZE;
                SDL_RenderFillRect(_renderer, &rect);
            }
        }
        // Render the pieces on top of the board
        for (int row = 0; row < _BOARD_SIZE; row++)
        {
            for (int col = 0; col < _BOARD_SIZE; col++)
            {
                if (_board[row][col].pieceObj) {
                    _board[row][col].pieceObj->render(_renderer, col * _SQUARE_SIZE, row * _SQUARE_SIZE, _SQUARE_SIZE);
                }
            }
        }

        SDL_RenderPresent(_renderer);
    }
    return 0;
}


void Board::initializeBoard() {
    for (int row = 0; row < _BOARD_SIZE; row++) {
        for (int col = 0; col < _BOARD_SIZE; col++) {
            ChessPiece::type pieceType = ChessPiece::Empty;
            ChessPiece::color pieceColor = ChessPiece::None;

            if (row == 0 || row == 7) {
                if (col == 0 || col == 7) {
                    pieceType = ChessPiece::Rook;
                }
                else if (col == 1 || col == 6) {
                    pieceType = ChessPiece::Knight;
                }
                else if (col == 2 || col == 5) {
                    pieceType = ChessPiece::Bishop;
                }
                else if (col == 3) {
                    pieceType = ChessPiece::Queen;
                }
                else {
                    pieceType = ChessPiece::King;
                }
            }
            else if (row == 1 || row == 6) {
                pieceType = ChessPiece::Pawn;
            }

            if (row <= 1) {
                pieceColor = ChessPiece::Black;
            }
            else if (row >= 6) {
                pieceColor = ChessPiece::White;
            }

            if (pieceType != ChessPiece::Empty) {
                _board[row][col] = ChessPiece(pieceType, pieceColor, _renderer);
            }
        }
    }
}
