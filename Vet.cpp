//
// Created by royivri on 9/25/25.
//

#include "Vet.h"

#include <stdexcept>


Vet& Vet::get_instance() {
    static Vet instance;
    return instance;
}


void add_animal(std::unique_ptr<Animal> animal) {
    if (!animal) {
        throw std::invalid_argument("Null animal cannot be added");
    }
    animals.emplace_back(std::move(animal));
}
