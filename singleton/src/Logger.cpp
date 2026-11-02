#include "Logger.hpp"
#include <iostream>

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

Logger::Logger()
{
    std::cout << "Logger instance created.\n";
}

Logger::~Logger()
{
    std::cout << "Logger instance destroyed.\n";
}

void Logger::addMessage(const std::string &msg)
{
    m_messages.push_back(msg);
}

void Logger::printMessages() const
{
    std::cout << "--- Printing Messages ---\n";
    for (const auto &msg : m_messages)
    {
        std::cout << msg << '\n';
    }
}