//
// Created by royivri on 9/25/25.
//

#include "Dog.h"

bool Dog::check_health() const {    /// EXTRA POINTS FOR 1 LINE ?
    return (temp >= 38 && temp <= 39.2) &&
           (breath >= 10 && breath <= 35) &&
           (
               (heart > 60 && heart < 100 && is_large) ||
               (heart > 100 && heart < 140 && !is_large)
           );



}
