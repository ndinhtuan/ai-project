#include "Bot.h"
#include <iostream>
#include <vector>

using std::vector;

// Định nghĩa Epsilon để so sánh 2 góc bằng nhau "không thế so sánh 2 float trực tiếp."
#define EPSILON 1e-4

Bot::Bot(int numPieces, Frame *frame, Piece **allPieces)
{

    this->frame = frame;
    this->allPieces = allPieces;
    this->currentPiece = NULL;
    this->numPieces = numPieces;
}

/*
+ Chọn piece đầu tiên cho lời giải, để làm init.
+ chọn piece có số góc ngoái < 180 (góc trong > 180) và khác 90 ít nhất 
    - nếu có nhiều piece có nhiều góc bằng nhau thì chọn piece ít đỉnh hơn.
+Nếu không tìm được Piece nào thỏa mãn thì trả về 1 piece random.
*/
Piece *Bot::chooseInitPiece()
{

    // chứa các Piece có số góc ngoài < 180 và khác 90 ít nhất
    vector<Piece *> angleConstraintPieces;
    int minSpecialAngles = 100;

    for (int i = 0; i < numPieces; i++)
    {

        int tmp = allPieces[i]->getNumSpecialAngles();

        if (minSpecialAngles > tmp)
        {

            minSpecialAngles = tmp;
            angleConstraintPieces.clear();
            angleConstraintPieces.push_back(allPieces[i]);
        }
        else if (minSpecialAngles == tmp)
        {
            angleConstraintPieces.push_back(allPieces[i]);
        }
    }

    int tmp = angleConstraintPieces.size();
    if (tmp == 0)
        return allPieces[0];

    int index = 0;
    int minVertices = angleConstraintPieces[0]->getNumVertices();
    for (int i = 1; i < tmp; i++)
    {

        if (minVertices > angleConstraintPieces[i]->getNumVertices())
        {

            index = i;
            minVertices = angleConstraintPieces[i]->getNumVertices();
        }
    }

    return allPieces[index];
}
