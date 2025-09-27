//
// Created by royivri on 9/25/25.
//

#ifndef VET_H
#define VET_H
#include <memory>
#include <vector>

#include "Animal.h"
/// TODO destructor should delete the animals it has


class Vet {
public:
    Vet(const Vet&) = delete;
    Vet& operator=(const Vet&) = delete;
    Vet(Vet&&) = delete;
    Vet& operator=(Vet&&) = delete;

    // Global access point
    static Vet& get_instance();


    void add_animal(Animal * &&);
    void show_sick() const;
    void show_sick_dogs() const;

private:
  
    Vet() {
        // initialization
    }
    std::vector<std::unique_ptr<Animal> > animals;
    ~Vet() = default;
};


#endif //VET_H
