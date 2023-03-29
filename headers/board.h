#pragma once
#include <SDL.h>
#include <iostream>

//Test
class DrawBoard 
{
public:
	int SDLinit();
	int renderBoard();
	int renderPieces();

private:
	const int BOARD_SIZE = 8;	 // Cells
	const int SQUARE_SIZE = 100; // Pixels

};