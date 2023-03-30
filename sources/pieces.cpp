//============================================================
// FILE: pieces.cpp
//============================================================
#include <pieces.h>
#include <SDL_image.h>
#include <iostream>

/*******************************************************************************
**  Helper Functions
*******************************************************************************/

std::string generateImagePath(ChessPieceImage::type pieceType, ChessPieceImage::color pieceColor) {
    std::string basePath = "textures/";
    std::string colorStr;
    std::string pieceStr;

    // Determine the appropriate color and piece strings based on the input parameters
    switch (pieceColor) {
    case ChessPieceImage::White:
        colorStr = "light";
        break;
    case ChessPieceImage::Black:
        colorStr = "dark";
        break;
    default:
        return ""; 
    }

    switch (pieceType) {
    case ChessPieceImage::Pawn:
        pieceStr = "Pawn";
        break;
    case ChessPieceImage::Knight:
        pieceStr = "Knight";
        break;
    case ChessPieceImage::Bishop:
        pieceStr = "Bishop";
        break;
    case ChessPieceImage::Rook:
        pieceStr = "Rook";
        break;
    case ChessPieceImage::Queen:
        pieceStr = "Queen";
        break;
    case ChessPieceImage::King:
        pieceStr = "King";
        break;
    default:
        return ""; 
    }
    // Combine the base path, color string, and piece string to form the complete image path
    return basePath + colorStr + pieceStr + ".png";
}

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Constructor
ChessPieceImage::ChessPieceImage(SDL_Renderer* renderer, ChessPieceImage::type pieceType, ChessPieceImage::color pieceColor)
{
    std::string imagePath = generateImagePath(pieceType, pieceColor);

    SDL_Surface* imageSurface = IMG_Load(imagePath.c_str());
    if (!imageSurface)
    {
        std::cerr << "Unable to load image \"" << imagePath << "\"! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    _texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    if (!_texture)
    {
        std::cerr << "Unable to create texture from \"" << imagePath << "\"! SDL Error: " << SDL_GetError() << std::endl;
    }
}

// Destructor
ChessPieceImage::~ChessPieceImage()
{
    SDL_DestroyTexture(_texture);
}

/*******************************************************************************
**  Public methods
*******************************************************************************/

void ChessPieceImage::render(SDL_Renderer* renderer, int x, int y, int squareSize)
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = squareSize;
    destRect.h = squareSize;
    SDL_RenderCopy(renderer, _texture, nullptr, &destRect);
}