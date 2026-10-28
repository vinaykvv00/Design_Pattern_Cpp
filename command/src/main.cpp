#include "command/Character.hpp"
#include "command/Command.hpp"
#include "command/MoveCommand.hpp"

#include <iostream>
#include <memory>
#include <random>
#include <vector>

namespace
{

void printPosition(const command::Character &character, const char *action)
{
    std::cout << character.name() << ' ' << action << " (" << character.x() << ", " << character.y()
              << ")\n";
}

} // namespace

int main()
{
    command::Character hero{"Hero"};

    std::mt19937 random{std::random_device{}()};
    std::uniform_int_distribution<int> coordinate{0, 9};

    std::vector<std::unique_ptr<command::Command>> history;
    for (int i = 0; i < 4; ++i)
    {
        const int x = coordinate(random);
        const int y = coordinate(random);
        history.push_back(std::make_unique<command::MoveCommand>(x, y));
    }

    for (const auto &move : history)
    {
        move->execute(hero);
        printPosition(hero, "moved to");
    }

    // Undo in reverse order: the most recent command is reversed first.
    for (auto move = history.rbegin(); move != history.rend(); ++move)
    {
        (*move)->undo(hero);
        printPosition(hero, "is back at");
    }

    return 0;
}
