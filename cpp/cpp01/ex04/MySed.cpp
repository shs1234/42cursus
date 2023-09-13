#include "MySed.hpp"

MySed::MySed(std::string ifilename, std::string s1, std::string s2)
{
	this->ifilename = ifilename;
	this->s1 = s1;
	this->s2 = s2;
	this->ofilename = ifilename + ".replace";
	this->infile.open(this->ifilename.c_str());
	this->outfile.open(this->ofilename.c_str());
}

void MySed::setval(std::string ifilename, std::string s1, std::string s2)
{
	this->ifilename = ifilename;
	this->s1 = s1;
	this->s2 = s2;
	this->ofilename = ifilename + ".replace";
	this->infile.open(this->ifilename.c_str());
	this->outfile.open(this->ofilename.c_str());
}

int MySed::is_open()
{
	if (!this->infile.is_open() || !this->outfile.is_open())
		return (0);
	return (1);
}

void MySed::close()
{
    this->infile.close();
    this->outfile.close();
}

static std::string replace(std::string &line, std::string &s1, std::string &s2)
{
	std::string ret;
	size_t start = 0;
	size_t end;

	while (1)
	{
		end = line.find(s1, start);
		if (end != std::string::npos)
		{
			ret += line.substr(start, end - start);
			ret += s2;
			start = end + s1.size();
		}
		else
			break ;
	}
	ret += line.substr(start, line.size() - start);
	return (ret);
}

void MySed::sed()
{
    std::string line;

    while (std::getline(this->infile, line))
    {
        line = replace(line, this->s1, this->s2);
        this->outfile << line;
		if (!this->infile.eof())
			this->outfile << std::endl;
    }
}
