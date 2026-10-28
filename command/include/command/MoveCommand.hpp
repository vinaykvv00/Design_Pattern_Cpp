#pragma once

#include "command/Command.hpp"

namespace command
{

class MoveCommand : public Command
{
public:
    MoveCommand(int targetX, int targetY);

    void execute(Character &character) override;
    void undo(Character &character) override;

private:
    int targetX_;
    int targetY_;
    int previousX_ = 0;
    int previousY_ = 0;
};

} // namespace command
