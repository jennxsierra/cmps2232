#include <iostream>
#include "Time.h"

int main() {
    Time t;

    std::cout << "The initial universal time is ";
    t.printUniversal();
    std::cout << std::endl;

    std::cout << "The initial standard time is ";
    t.printStandard();
    std::cout << std::endl;

    t.setTime(13, 27, 6);

    std::cout << "\nUniversal time after setTime is ";
    t.printUniversal();
    std::cout << std::endl;

    std::cout << "Standard time after setTime is ";
    t.printStandard();
    std::cout << std::endl;

    try {
        t.setTime(99, 99, 99);
    } catch (std::invalid_argument &e) {
        std::cout << "\nException: " << e.what() << std::endl;
    }

    std::cout << "\nAfter attempting invalid settings: " << std::endl;
    std::cout << "Universal time: ";
    t.printUniversal();
    std::cout << std::endl;
    std::cout << "Standard time: ";
    t.printStandard();
    std::cout << std::endl;

    return 0;
}