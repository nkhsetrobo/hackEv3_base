#include "Block.h"
#include "ev3api.h"

Block::Block(COLOR col)
{
    color = col;

}

COLOR Block::getColor()
{
    return color;
}

void Block::setColor(COLOR col)
{
   // printf("block %d->%d",color,(int)col);
    color = col;
}