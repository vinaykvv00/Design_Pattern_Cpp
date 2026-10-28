#pragma once

#include "command/Character.hpp"

namespace command
{

class Command
{
public:
    virtual ~Command() = default;

    virtual void execute(Character &character) = 0;
    virtual void undo(Character &character) = 0;
};

} // namespace command
