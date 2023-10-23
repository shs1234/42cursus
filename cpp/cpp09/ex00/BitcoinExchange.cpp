#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string data, std::string input)
: _data(data), _input(input)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& be)
{
    (void)be;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& be)
{
    if (this != &be)
        (void)be;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::readData()
{
    std::string line;
    std::size_t pos;

    _datafile.open(_data.c_str());
    if (!_datafile.is_open())
        throw DataOpenFail();
    std::getline(_datafile, line);
    while (std::getline(_datafile, line))
    {
        pos = line.find(',');
        _dataMap.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1)));
    }
    // std::map<std::string, std::string>::iterator it = _dataMap.begin();
    // for (; it != _dataMap.end(); it++)
    //     std::cout << "key : " << it->first << " val : " << it->second << std::endl;
}

bool BitcoinExchange::errorCheck()
{
    _pos = _line.find(" | ");
    if (_pos == std::string::npos)
    {
        std::cout << "Error: bad input => " << _line << std::endl;
        return (0);
    }
    _key = _line.substr(0, _pos);
    _val = _line.substr(_pos + 3);
    std::istringstream(_val) >> _val_f;
    // val이 float형태인지. 소수점 하나의 모두 숫자만.
    return (1);
}

void BitcoinExchange::printResult()
{
    _pos = _line.find(" | ");
    std::cout << _line.substr(0, _pos) << " => " << _line.substr(_pos + 3) << " = " << "Res" << std::endl;
}

void BitcoinExchange::exchange()
{
    _inputfile.open(_input.c_str());
    if (!_inputfile.is_open())
        throw InputOpenFail();
    std::getline(_inputfile, _line);
    if (_line != "date | value")
    {
        if (errorCheck())
            printResult();
    }
    while (std::getline(_inputfile, _line))
    {
        if (errorCheck())
            printResult();
    }
}

const char *BitcoinExchange::DataOpenFail::what() const throw()
{
    return ("Error: could not open data file.");
}
const char *BitcoinExchange::InputOpenFail::what() const throw()
{
    return ("Error: could not open input file.");
}
