//
// Created by royivri on 9/25/25.
//

#include "Cat.h"


bool Cat::check_health() const {
    return (temp >= 38 && temp <= 39.2) &&
       (breath >= 16 && breath <= 40) &&
       (heart >= 120 && heart <= 140);

}
