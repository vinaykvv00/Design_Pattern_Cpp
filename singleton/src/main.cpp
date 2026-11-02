#include "Logger.hpp"

int main()
{
    Logger::getInstance().addMessage("Hello, Singleton Logger1");
    Logger::getInstance().addMessage("Hello, Singleton Logger2");
    Logger::getInstance().addMessage("Hello, Singleton Logger3");

    Logger::getInstance().printMessages();

    return 0;
}