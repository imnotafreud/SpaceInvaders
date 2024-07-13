#include "block.h"

Block::Block(Vector2 position)
{
    this->pos = position;
}

void Block::Draw()
{
    DrawRectangle(pos.x, pos.y, 3, 3, {243, 216, 63, 255});
}

Rectangle Block::getRect()
{
    Rectangle rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.width = 3;
    rect.height = 3;
    return rect;

}
