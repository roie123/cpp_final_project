//
// Created by royivri on 9/25/25.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>


class Animal {
public:
    virtual ~Animal() = default;

    Animal(std::string name_,double temp_,double breath_,double heart_);
    virtual bool check_health();






protected:
    std::string name;
    double temp; //animal temp in C
    double breath;//breaths per minute
    double heart; //heart rate - beats per minute
};



#endif //ANIMAL_H
