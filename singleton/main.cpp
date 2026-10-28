#include <iostream>
#include <vector>

class Logger
{
public:
    // retrive the single instances of the object
    //  created and we will enforce that only one instance exists
    //  objects gets created in our code logic only when needed

    // this & better compare to * , thread safe and ensures single instance is created only once
    static Logger &getInstance()
    {
        static Logger *s_instance = new Logger;
        return *s_instance;
    }

    void printMessages()
    {
        std::cout << "Printing messages:" << std::endl;
        for (const auto &msg : m_messages)
        {
            std::cout << msg << std::endl;
        }
    }
    void addMessage(const std::string s)
    {
        m_messages.push_back(s);
    }

private:
    Logger()
    {
        std::cout << "Logger instance created:" << std::endl;
    }
    ~Logger()
    {
        std::cout << "Logger instance destroyed:" << std::endl;
    }

    static Logger *s_instance;
    std::vector<std::string> m_messages;
};

// Logger *Logger::s_instance = nullptr;

int main()
{
    Logger::getInstance().addMessage("Hello, signleton message 1");
    Logger::getInstance().addMessage("Hello, signleton message 2");
    Logger::getInstance().addMessage("Hello, signleton message 3");
    Logger::getInstance().printMessages();

    // Logger &pointer_to_logger = Logger::getInstance();
    // delete &pointer_to_logger; // destructor is private its good, but if its not there
    // Logger::getInstance().addMessage("Hello, signleton message 4"); // here we will get the
    // segmentation fault because the
    // previous instance was deleted

    return 0;
}