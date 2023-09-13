#ifndef MYSED_HPP
#define MYSED_HPP

#include <iostream>
#include <fstream>

class MySed
{
private:
    std::string ifilename;
    std::string s1;
    std::string s2;
    std::string ofilename;

    std::ifstream infile;
    std::ofstream outfile;

public:
    MySed(std::string ifilename, std::string s1, std::string s2);
    void setval(std::string ifilename, std::string s1, std::string s2);
    int is_open();
    void close();
    void sed();
};

#endif
