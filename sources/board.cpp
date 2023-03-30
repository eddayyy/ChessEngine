#include "board.h"
#include <SDL.h>
#include <iostream>


/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
// Constructor
Board::Board()
{
    SDLinit();
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
    SDLinit();
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
        SDL_RenderPresent(_renderer);
    }
    return 0;
}


void Board::loadPieceImages()
{

}