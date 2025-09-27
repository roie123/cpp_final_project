//
// Created by royivri on 9/25/25.
//

#ifndef CAT_H
#define CAT_H
#include "Animal.h"


class Cat :public Animal{
public:
    Cat(const std::string &name_, double temp_, double breath_, double heart_)
        : Animal(name_, temp_, breath_, heart_) {
    }


    bool check_health() const override;



};



#endif //CAT_H
