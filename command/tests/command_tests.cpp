#include "command/Character.hpp"
#include "command/MoveCommand.hpp"

#include <cstdlib>
#include <iostream>

namespace
{

bool expectPosition(const command::Character &character, int x, int y)
{
    if (character.x() == x && character.y() == y)
    {
        return true;
    }
    std::cerr << "Expected (" << x << ", " << y << ") but got (" << character.x() << ", "
              << character.y() << ")\n";
    return false;
}

} // namespace

int main()
{
    command::Character hero{"Hero"};
    command::MoveCommand first{3, 6};
    command::MoveCommand second{7, 5};

    first.execute(hero);
    second.execute(hero);
    bool ok = expectPosition(hero, 7, 5);

    second.undo(hero);
    ok = expectPosition(hero, 3, 6) && ok;

    first.undo(hero);
    ok = expectPosition(hero, 0, 0) && ok;

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
