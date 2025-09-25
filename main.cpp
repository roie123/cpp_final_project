#include <iostream>

#include "Equation.h"
#include "Vet.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    using namespace std;
    // Equation eq(10,20,30);
    // cout << eq << endl;
    // //should print: 10X^2 + 20X + 30 = 0
    // cout << eq.get_solutions_size() << endl;
    // //should print 0
    // eq = -20 + eq;
    // cout << eq << endl;
    // //should print: 10X^2 + 20X + 10 = 0
    // cout << eq.get_solutions_size() << endl;
    // //should print 1
    // cout << eq.get_solutions()[0] << endl;
    // //should print -1
    // cout << Equation(1,5,3) + Equation(2,6,4) << endl;
    // //should print: 3X^2 + 11X + 7 = 0
    // eq = Equation(1,3,-4);
    // cout << eq << endl;
    // //should print 1X^2 + 3X + -4 = 0
    // cout << eq.get_solutions_size() << endl;
    // //should print 2
    // cout << "X1 = " << eq.get_solutions()[0] << endl;
    // //should print: X1 = 1
    // cout << "X2 = " << eq.get_solutions()[1] << endl;
    // //should print: X2 = -4


    cout << "program start" << endl;
    Vet &vet = Vet::get_instance(); //healthy dog
    vet.add_animal(new Dog("dog1", 38.5, 20, 80, true));
    //not healthy dog (temp too high)
    vet.add_animal(new Dog("dog2", 40.0, 20, 80, true));
    //not healthy dog (heart rate too slow for a small breed)
    vet.add_animal(new Dog("dog3", 38.5, 20, 80, false));
    //healthy cat
    vet.add_animal(new Cat("cat1", 38.7, 30, 130));
    //not healthy cat (breath is too high)
    vet.add_animal(new Cat("cat2", 38.7, 42, 130));
    //healthy cow
    vet.add_animal(new Cow("cow1", 39.0, 37, 70, 32);
    //not healthy cow (milk production too low)
    vet.add_animal(new Cow("cow2", 39.0, 37, 70, 20);
}

vet
.
show_sick(); //should print: dog2 dog3 cat2 cow2
vet
.
show_sick_dogs(); //should print: dog2 dog3
}
