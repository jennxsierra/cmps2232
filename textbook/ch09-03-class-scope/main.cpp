#include <iostream>

class Count {
public:
    void setX(int value) {
        x = value;
    }

    void print() const {
        std::cout << x << std::endl;
    }

private:
    int x{0};
};

int main() {

    Count counter{};
    Count *counterPtr = &counter;
    Count &counterRef = counter;

    std::cout << "Set x to 1 and print using the object name: ";
    counter.setX(1);
    counter.print();

    std::cout << "Set x to 2 and print using a reference to an object: ";
    counterRef.setX(2);
    counterRef.print();

    std::cout << "Set x to 3 and print using a pointer to an object: ";
    counterPtr->setX(3);
    counterPtr->print();

    return 0;
}