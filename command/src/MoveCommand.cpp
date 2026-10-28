#include "command/MoveCommand.hpp"

namespace command
{

MoveCommand::MoveCommand(int targetX, int targetY) : targetX_(targetX), targetY_(targetY) {}

void MoveCommand::execute(Character &character)
{
    previousX_ = character.x();
    previousY_ = character.y();
    character.moveTo(targetX_, targetY_);
}

void MoveCommand::undo(Character &character)
{
    character.moveTo(previousX_, previousY_);
}

} // namespace command
