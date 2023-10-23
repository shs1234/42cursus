#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>

class BitcoinExchange
{
private:
    std::string _data;
    std::string _input;
    std::ifstream _datafile;
    std::ifstream _inputfile;
    std::map<std::string, std::string> _dataMap;

    std::string _line;
    std::size_t _pos;
    std::string _key;
    std::string _val;
    float _val_f;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& be);
    BitcoinExchange& operator=(const BitcoinExchange& be);

    bool errorCheck();
    void printResult();

public:
    BitcoinExchange(std::string data, std::string input);
    ~BitcoinExchange();

    void readData();
    void exchange();

    class DataOpenFail : public std::exception
    {
        const char *what() const throw();
    };
    class InputOpenFail : public std::exception
    {
        const char *what() const throw();
    };
};

#endif
