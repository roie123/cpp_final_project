//
// Created by royivri on 9/25/25.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>


class Animal {
public:
    virtual ~Animal() = default;

    Animal(std::string name_, double temp_, double breath_, double heart_)
    : name(std::move(name_)), temp(temp_), breath(breath_), heart(heart_) {}

    virtual bool check_health() const=0;


    // Getters
    std::string get_name() const { return name; }
    double get_temp() const { return temp; }
    double get_breath() const { return breath; }
    double get_heart() const { return heart; }

    // Setters
    void set_temp(double t) { temp = t; }
    void set_breath(double b) { breath = b; }
    void set_heart(double h) { heart = h; }



protected:
    const std::string name; // a name once given
    double temp; //animal temp in C
    double breath;//breaths per minute
    double heart; //heart rate - beats per minute
};



#endif //ANIMAL_H
