#pragma once

#include <string>

namespace command
{

// Receiver: owns the state that commands change.
class Character
{
public:
    explicit Character(std::string name);

    void moveTo(int x, int y);

    const std::string &name() const
    {
        return name_;
    }
    int x() const
    {
        return x_;
    }
    int y() const
    {
        return y_;
    }

private:
    std::string name_;
    int x_ = 0;
    int y_ = 0;
};

} // namespace command
