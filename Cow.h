//
// Created by royivri on 9/25/25.
//

#ifndef COW_H
#define COW_H
#include "Animal.h"


class Cow:public Animal {
public:
    Cow(const std::string &name_, double temp_, double breath_, double heart_, double milk)
        : Animal(name_, temp_, breath_, heart_),
          milk(milk) {
    }
    bool check_health() override;

private:
    double milk; //amount of liters per day the cow produces
};



#endif //COW_H
