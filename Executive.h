#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <string>
#include <fstream>

class Executive
{
private:
    std::fstream m_dataFile;
    std::string m_fileName;

public:
    Executive(std::string fileName) { m_fileName = fileName; };
    void run();
};

#endif