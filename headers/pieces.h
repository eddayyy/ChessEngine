//============================================================
// FILE: pieces.h
//============================================================
#pragma once
#include <SDL.h>
#include <memory>
#include <string>

class ChessPieceImage {
public:
    // Enumerations
    enum  type { Empty, Pawn, Knight, Bishop, Rook, Queen, King };
    enum  color { None, White, Black };

    // Constructors, assignments, and destructor
    ChessPieceImage(SDL_Renderer* renderer, type pieceType, color pieceColor);
    ~ChessPieceImage();

    // Public methods
    void render(SDL_Renderer* renderer, int x, int y, int squareSize);

private:
    // Private members
    SDL_Texture* _texture;
};
