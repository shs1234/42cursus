#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>
#include <algorithm>

class BitcoinExchange
{
private:
    std::string _data;
    std::string _input;
    std::map<std::string, std::string> _dataMap;

    std::string _line;
    std::size_t _pos;
    std::string _key;
    std::string _val;

    std::string _date[3];
    int _firstYear;
    float _val_f;

    BitcoinExchange();

    void errorCheck();
    void printRes();
    bool isLeapYear(int year);
    int lastDay(int year, int month);

public:
    BitcoinExchange(std::string data, std::string input);
    BitcoinExchange(const BitcoinExchange& be);
    BitcoinExchange& operator=(const BitcoinExchange& be);
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
    class BadInput : public std::exception
    {
        const char *what() const throw();
    };
};
