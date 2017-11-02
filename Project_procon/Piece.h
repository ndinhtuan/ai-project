/*
- class Piece inherit from Frame. Describe Piece
- TO-DO : rotate piece ------> Kiên
*/

#ifndef PIECE_H
#define PIECE_H
#include "Frame.h"

class Piece: public Frame{
public:
    Piece();
    Piece(int numVertices, int id);
};

#endif
