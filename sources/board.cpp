#include "board.h"
#include <SDL.h>
#include <iostream>


int SDLinit()
{
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
    {
        std::cerr << "SDL could not initialize!\nSDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

}


int DrawBoard::renderBoard()
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
        while ( SDL_WaitEvent( &e ) )
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
                if ((row + col) % 2 == 0)    // Light Color Square
                {

                }
            }
        }
    }
}