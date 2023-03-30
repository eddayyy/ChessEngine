#pragma once
#include <SDL.h>
#include <memory>
#include <string>

// Move the ChessPiece struct definition above the ChessPieceImage class definition
struct ChessPiece {
    enum type { Empty, Pawn, Knight, Bishop, Rook, Queen, King };
    enum color { None, White, Black };

    type  Piece;
    color Team;
    std::shared_ptr<class ChessPieceImage> pieceObj;


    ChessPiece() : Piece(Empty), Team(None), pieceObj(nullptr) {}
    ChessPiece(ChessPiece::type pieceType, ChessPiece::color pieceColor, SDL_Renderer* renderer)
               : Piece(pieceType), Team(pieceColor), pieceObj(std::make_shared<ChessPieceImage>(renderer, pieceType, pieceColor)) {}
};

class ChessPieceImage {
public:
    ChessPieceImage(SDL_Renderer* renderer, ChessPiece::type pieceType, ChessPiece::color pieceColor);
    ~ChessPieceImage();

    void render(SDL_Renderer* renderer, int x, int y, int squareSize);

private:
    SDL_Texture* _texture;
};
