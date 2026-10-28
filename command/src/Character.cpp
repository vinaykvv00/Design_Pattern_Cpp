#include "command/Character.hpp"

#include <utility>

namespace command
{

Character::Character(std::string name) : name_(std::move(name)) {}

void Character::moveTo(int x, int y)
{
    x_ = x;
    y_ = y;
}

} // namespace command
