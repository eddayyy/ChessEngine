#pragma once
#include <SDL.h>

#include <memory>
#include <string>


class ChessPieceImage {
public:
    ChessPieceImage(SDL_Renderer* renderer, const std::string& imagePath);
    ~ChessPieceImage();

    void renderPieces(SDL_Renderer* renderer, int x, int y, int squareSize);

private:
    SDL_Texture* _texture;
};

struct ChessPiece {
    enum type  { Empty, Pawn, Knight, Bishop, Rook, Queen, King };
    enum color { None, White, Black };

    type  Piece;
    color Team;
    std::shared_ptr<ChessPieceImage> pieceObj;
};

