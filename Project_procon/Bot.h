#ifndef BOT_H
#define BOT_H

#include "Frame.h"
#include "Piece.h"

class Bot
{
  public:
    Bot(int numPieces, Frame *frame, Piece **allPieces);
    ~Bot();

    /*  
    + Hàm này chọn Piece làm mảnh Init có ưu tiên 
    */
    Piece *chooseInitPiece();
    /*
    + chooseNextVariabel() chọn đỉnh tiếp theo để ghép hình, đinh tiếp theo là các đỉnh trong số các đỉnh 
        của currentPiece
    */
    int chooseNextVariabel();
    /*
    + getValues(int index) tìm các value (biến thể của Piece)
    @ trả về list các phương án có thể phù hợp với currentPiece tại đỉnh index
    */
    void getValues(int index);

  private:
    Frame *frame;
    Piece **allPieces;
    Piece *currentPiece; // lời giải hiện tại. Chứa tấp các piece đã ghép thành công.
    int numPieces;
};

#endif
