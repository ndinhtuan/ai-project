#include "Frame.h"
#include <cassert>
#include <iostream>
#include <cstddef>

using std::endl;

Frame::Frame(int numVertices, int id) {

    this->numVertices = numVertices;
    this->angles = new float[numVertices];
    this->vertices = new Dot*[numVertices];
    this->squareEdge = new int[numVertices];
    this->id = id;

    for (int i = 0; i < numVertices; i++) {
        this->vertices[i] = new Dot();
    }
}

Frame::Frame(){

}

void Frame::setCoord(int index, int x, int y) {

    assert(this->numVertices > 0 && this->vertices != NULL);
    this->vertices[index]->x = x;
    this->vertices[index]->y = y;
}

void Frame::setCoord(int index, const Dot &coord) {
    
    assert(this->numVertices > 0 && this->vertices != NULL);    
    this->vertices[index]->x = coord.x;
    this->vertices[index]->y = coord.y;
}

ostream& operator<<(ostream &os, const Frame &frame) {

    os << "ID : " << frame.id << endl;
    os << "#vertices : " << frame.numVertices << endl;

    for (int i = 0; i < frame.numVertices; i++) {

        os << "(" << frame.vertices[i]->x << ", " << frame.vertices[i]->y << "); ";
    }
    os << endl;

    return os;
}