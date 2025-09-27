//
// Created by royivri on 9/25/25.
//

#ifndef DOG_H
#define DOG_H
#include "Animal.h"


class Dog :public Animal{
public:
    Dog(const std::string &name_, double temp_, double breath_, double heart_,bool is_large_)
        : Animal(name_, temp_, breath_, heart_) , is_large(is_large_) {

    }

    bool check_health() const override;





private:
    bool is_large;

};



#endif //DOG_H
