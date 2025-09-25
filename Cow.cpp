//
// Created by royivri on 9/25/25.
//

#include "Cow.h"

bool Cow::check_health() {
    return (temp >= 38.5 && temp <= 39.5) &&
       (breath >= 26 && breath <= 50) &&
       (heart >= 48 && heart <= 84) &&
       (milk >= 30);

}
