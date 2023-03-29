#include "board.h"
#include <SDL.h>
#include <iostream>


int Board::SDLinit()
{
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
    {
        std::cerr << "SDL could not initialize!\nSDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}


int Board::renderBoard()
{
    SDLinit();
    SDL_Window* window = SDL_CreateWindow("Chess Engine",
                         SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED,
                         BOARD_SIZE * SQUARE_SIZE,
                         BOARD_SIZE * SQUARE_SIZE,
                         SDL_WINDOW_SHOWN);
    if ( !window )
    {
        std::cerr << "Could not create window\nSDL_Error: " << SDL_GetError();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if (!renderer) 
    {
        std::cerr << "Renderer could not be created\nSDL Error: " << SDL_GetError();
        return 1;
    }
    
    bool quit = false;
    SDL_Event e;

    while ( !quit )
    {
        while ( SDL_PollEvent( &e ) )
        {
            if ( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        SDL_RenderClear( renderer );

        // Iterate through each square on the board 
        for ( int row = 0; row < BOARD_SIZE; row++ )
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if ((row + col) % 2 == 0)
                {
                    SDL_SetRenderDrawColor( renderer, 240, 217, 181, 255 ); // Light squares
                }
                else 
                {
                    SDL_SetRenderDrawColor( renderer, 181, 136, 99, 255  );  // Dark square
                }
                SDL_Rect rect;                                              // Rectangle Struct: int x, y, width, height
                rect.x = col * SQUARE_SIZE;
                rect.y = row * SQUARE_SIZE;
                rect.w = SQUARE_SIZE;
                rect.h = SQUARE_SIZE;
                SDL_RenderFillRect( renderer, &rect );
            }
        }
        SDL_RenderPresent( renderer );
    }
    return 0;
}

void Board::destroyBoard( SDL_Renderer* renderer, SDL_Window* window ) {
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow(window);
    SDL_Quit();
}