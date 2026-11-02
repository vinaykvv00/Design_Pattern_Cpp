#pragma once

#include <iostream>
#include <string>
#include <vector>

class Logger
{
public:
    // Delete copy constructor and assignment operator
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    // Delete move constructor and assignment operator
    Logger(Logger &&) = delete;
    Logger &operator=(Logger &&) = delete;

    // access for the singleton instance
    static Logger &getInstance();

    void addMessage(const std::string &msg);
    void printMessages() const;

private:
    Logger();
    ~Logger();

    std::vector<std::string> m_messages;
};