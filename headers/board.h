#pragma once
#include <SDL.h>
#include <iostream>


class Board 
{
public:
	Board();
	~Board();

	int		SDLinit		();
	int		renderBoard	();
	void	renderChar	(char c, int x, int y, int charWidth, int charHeight, SDL_Texture* bitmapFont, SDL_Renderer* renderer);

private:
	const int BOARD_SIZE  = 8;   // Cells
	const int SQUARE_SIZE = 100; // Pixels
	SDL_Window* window;
	SDL_Renderer* renderer;
};
