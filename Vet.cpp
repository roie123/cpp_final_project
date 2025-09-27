//
// Created by royivri on 9/25/25.
//

#include "Vet.h"
#include "Dog.h"
#include <iostream>
#include <stdexcept>


Vet& Vet::get_instance() {
    static Vet instance;
    return instance;
}

void Vet::add_animal(Animal *&& animal) {
    animals.emplace_back(std::unique_ptr<Animal>(animal));
}

void Vet::show_sick() const {
    for (const auto& animal : animals) {
        if (!animal->check_health()) {
            std::cout << animal->get_name()+ " "  ;
        }
    }
    std::cout << std::endl;
}

void Vet::show_sick_dogs() const {
    for (const auto& animal : animals) {
        // check if this animal is a Dog
        const Dog* dog = dynamic_cast<const Dog*>(animal.get());
        if (dog && !dog->check_health()) {
            std::cout << dog->get_name() << " (Dog) is sick." << std::endl;
        }
    }

}

