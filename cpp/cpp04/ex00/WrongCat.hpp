#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat& wrongcat);
    WrongCat& operator=(const WrongCat& wrongcat);
    ~WrongCat();

    void makeSound() const;
    const std::string &getType() const;
};

#endif
