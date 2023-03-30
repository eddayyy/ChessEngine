#include <pieces.h>
#include <SDL_image.h>
#include <iostream>

// Helper function to generate image path
std::string generateImagePath(ChessPiece::type pieceType, ChessPiece::color pieceColor) {
    std::string basePath = "textures/"; 
    std::string colorStr;
    std::string pieceStr;

    switch (pieceColor) {
    case ChessPiece::White:
        colorStr = "light";
        break;
    case ChessPiece::Black:
        colorStr = "dark";
        break;
    default:
        return ""; // Return an empty string if the color is not valid
    }

    switch (pieceType) {
    case ChessPiece::Pawn:
        pieceStr = "Pawn";
        break;
    case ChessPiece::Knight:
        pieceStr = "Knight";
        break;
    case ChessPiece::Bishop:
        pieceStr = "Bishop";
        break;
    case ChessPiece::Rook:
        pieceStr = "Rook";
        break;
    case ChessPiece::Queen:
        pieceStr = "Queen";
        break;
    case ChessPiece::King:
        pieceStr = "King";
        break;
    default:
        return ""; // Return an empty string if the piece type is not valid
    }

    return basePath + colorStr + pieceStr + ".png";
}


ChessPieceImage::ChessPieceImage(SDL_Renderer* renderer, ChessPiece::type pieceType, ChessPiece::color pieceColor)
{
    // Generate the image path based on pieceType and pieceColor
    std::string imagePath = generateImagePath(pieceType, pieceColor);

    // Load image file and create SDL_Surface from it
    SDL_Surface* imageSurface = IMG_Load(imagePath.c_str());
    if (imageSurface == nullptr)
    {
        std::cerr << "Unable to load image \"" << imagePath << "\"! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Convert SDL_Surface to SDL_Texture
    _texture = SDL_CreateTextureFromSurface(renderer, imageSurface);

    // Free the SDL_Surface as it is no longer needed
    SDL_FreeSurface(imageSurface);

    if (_texture == nullptr)
    {
        std::cerr << "Unable to create texture from \"" << imagePath << "\"! SDL Error: " << SDL_GetError() << std::endl;
    }
}

ChessPieceImage::~ChessPieceImage()
{
    SDL_DestroyTexture(_texture);
}

void ChessPieceImage::render(SDL_Renderer* renderer, int x, int y, int squareSize)
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = squareSize;
    destRect.h = squareSize;
    SDL_RenderCopy(renderer, _texture, nullptr, &destRect);
}