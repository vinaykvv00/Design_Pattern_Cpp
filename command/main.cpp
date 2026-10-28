#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

struct Character
{
    int x;
    int y;
    std::string name;
    Character(std::string _name) : name(_name) {}
    void move(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Character &ch) = 0;
    virtual void undo(Character &ch) = 0;
};

class Move : public Command
{
public:
    void execute(Character &ch) override
    {
        int randomX = std::rand() % 10;
        int randomY = std::rand() % 10;
        ch.move(randomX, randomY);
        x = randomX;
        y = randomY;
        std::cout << ch.name << " moved to (" << x << ", " << y << ")" << std::endl;
    }
    void undo(Character &ch) override
    {
        ch.move(-x, -y);
        std::cout << ch.name << " moved back to (" << -x << ", " << -y << ")" << std::endl;
    }

private:
    int x;
    int y;
};
// this file should be there just all at once for reference for manual one file, dont split or
// remove or include any part for other . this just to understand the whole pattern in one file
// g++ -std=c++17 main.cpp -o main
int main()
{
    Character ch1("Hero");

    std::vector<Command *> command_queue;

    Move *m1 = new Move();
    command_queue.push_back(m1);
    Move *m2 = new Move();
    command_queue.push_back(m2);
    Move *m3 = new Move();
    command_queue.push_back(m3);
    Move *m4 = new Move();
    command_queue.push_back(m4);

    // for (Command* cmd : command_queue) {
    //     cmd->execute(ch1);
    // }

    for (int i = 0; i < command_queue.size(); ++i)
    {
        command_queue[i]->execute(ch1);
    }

    for (int i = command_queue.size() - 1; i >= 0; --i)
    {
        command_queue[i]->undo(ch1);
    }

    return 0;
}