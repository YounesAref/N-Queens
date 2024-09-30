#include "queen.h"

//assiging constructors
Queen::Queen(){}

Queen::Queen(int coloumn, int negDiagonal, int posDiagonal){
    this->coloumn = coloumn;
    this->negDiagonal = negDiagonal;
    this->posDiagonal = posDiagonal;
}

//making getters and setters
int Queen::getNegDiagonal(){
    return negDiagonal;
}

int Queen::getColoumn(){
    return coloumn;
}

int Queen::getPosDiagonal(){
    return posDiagonal;
}

void Queen::setNegDiagonal(int negDiagonal){
    this->negDiagonal = negDiagonal;
}

void Queen::setPosDiagonal(int posDiagonal){
    this->posDiagonal = posDiagonal;
}

void Queen::setColoumn(int coloumn){
    this->coloumn = coloumn;
}
