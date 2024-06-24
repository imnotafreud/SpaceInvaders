#include "block.h"

Block::Block(Vector2 position)
{
    this->pos = position;
}

void Block::Draw()
{
    DrawRectangle(pos.x, pos.y, 3, 3, {243, 216, 63, 255});
}
