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
    _data = be._data;
    _input = be._input;
    _dataMap.clear();
    _dataMap = be._dataMap;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& be)
{
    if (this != &be)
    {
        _data = be._data;
        _input = be._input;
        _dataMap.clear();
        _dataMap = be._dataMap;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::readData()
{
    std::ifstream _datafile;
    _datafile.open(_data.c_str());
    if (!_datafile.is_open())
        throw DataOpenFail();
    _dataMap.clear();
    std::getline(_datafile, _line);
    while (std::getline(_datafile, _line))
    {
        _pos = _line.find(',');
        _dataMap.insert(std::make_pair(_line.substr(0, _pos), _line.substr(_pos + 1)));
    }
    std::istringstream(_dataMap.begin()->first) >> _firstYear;
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int BitcoinExchange::lastDay(int year, int month)
{
    int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        m[1] = 29;
    return (m[month - 1]);
}

void BitcoinExchange::errorCheck()
{
    int date[3];
    
    _pos = _line.find(" | ");
    if (_pos == std::string::npos)
        throw BadInput();
    _key = _line.substr(0, _pos);
    _val = _line.substr(_pos + 3);
    // date 검사
    if (_key.size() != 10)
        throw BadInput();
    if (std::count(_key.begin(), _key.end(), '-') != 2)
        throw BadInput();
    if (_key[4] != '-' || _key[7] != '-')
        throw BadInput();
    std::istringstream iss(_key);
    std::getline(iss, _date[0], '-');
	std::getline(iss, _date[1], '-');
	std::getline(iss, _date[2]);
    if (!(std::istringstream(_date[0]) >> date[0] && date[0] >= _firstYear && date[0] <= 9999)
    || !(std::istringstream(_date[1]) >> date[1] && date[1] >= 1 && date[1] <= 12)
    || !(std::istringstream(_date[2]) >> date[2] && date[2] >= 1 && date[2] <= lastDay(date[0], date[1])))
        throw BadInput();
    // value 검사
    std::size_t dotCount = 0;
    std::size_t numCount = 0;
    std::string::iterator it = _val.begin();
    for (; it != _val.end(); it++)
    {
        if (*it == '.')
            dotCount++;
        else if (isdigit(*it))
            numCount++;
    }
    if (dotCount > 1 || dotCount + numCount != _val.size() || *_val.begin() == '.' || *_val.rbegin() == '.')
        throw BadInput();
    if (!(std::istringstream(_val) >> _val_f && _val_f >= 0 && _val_f <= 1000))
        throw BadInput();
}

void BitcoinExchange::printRes()
{
    float a;
    std::map<std::string, std::string>::reverse_iterator it = _dataMap.rbegin();
    for (; it != _dataMap.rend(); it++)
    {
        if (it->first <= _key)
        {
            std::istringstream(it->second) >> a;
            std::cout << _line << " = " << a * _val_f << std::endl;
            return;
        }
    }
    throw BadInput();
}

void BitcoinExchange::exchange()
{
    std::ifstream _inputfile;
    _inputfile.open(_input.c_str());
    if (!_inputfile.is_open())
        throw InputOpenFail();
    // std::cout << std::fixed;
    // std::cout.precision(10);
    std::getline(_inputfile, _line);
    if (_line != "date | value")
    {
        try
        {
            errorCheck();
            printRes();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    while (std::getline(_inputfile, _line))
    {
        try
        {
            errorCheck();
            printRes();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
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
const char *BitcoinExchange::BadInput::what() const throw()
{
    return ("Error: bad input.");
}
