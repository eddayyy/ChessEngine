#pragma once
#include <SDL.h>
#include <iostream>

//Test
class Board
{
public:
	int SDLinit();
	int renderBoard();
	void destroyBoard( SDL_Renderer* renderer, SDL_Window* window );

private:
	const int BOARD_SIZE = 8;	 // Cells
	const int SQUARE_SIZE = 100; // Pixels

};