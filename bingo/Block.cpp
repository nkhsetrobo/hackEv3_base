#include "Block.h"

Block::Block(int color, int no){
    Block::color = color;
    Block::no = no;
    dx = 0;
    dy = 0;
    flag = 0;
}

void Block::setBlockStorage(BlockStorage *blockstorage){
    Block::blockstorage = blockstorage;
}

void Block::setRunningBody(RunningBody *runningbody){
    Block::runningbody = runningbody;
}

void Block::setColor(int color){
    Block::color = color;
}

void Block::setNo(int no){
    Block::no = no;
}

void Block::setdX_Y(int x, int y){
    dx = x;
    dy = y;
}

void Block::setFlag(int flag){
    Block::flag = flag;
}

int Block::getColor(){
    return color;
}

int Block::getNo(){
    return no;
}

int Block::getX(){
    return blockstorage->getX();
}

int Block::getY(){
    return blockstorage->getY();
}

int Block::getdX(){
    return dx;
}

int Block::getdY(){
    return dy;
}

int Block::getFlag(){
    return flag;
}