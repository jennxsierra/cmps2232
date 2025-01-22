#include <iostream>
#include <iomanip>
#include "SalesPerson.h"

SalesPerson::SalesPerson() {
    for (int i{0}; i < monthsPerYear; ++i) {
        sales[i] = 0.0;
    }
}

void SalesPerson::getSalesFromUser() {
    double salesFigure;

    for (int i{1}; i <= monthsPerYear; ++i) {
        std::cout << "Enter sales amount for month " << i << ": ";
        std::cin >> salesFigure;
        setSales(i, salesFigure);
    }
}

void SalesPerson::setSales(int month, double amount) {
    if (month >= 1 && month <= monthsPerYear && amount > 0) {
        sales[month - 1] = amount;
    } else {
        std::cout << "Invalid month or sales figure" << std::endl;
    }
}

void SalesPerson::printAnnualSales() const {
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\nThe total annual sales are: $" << totalAnnualSales() << std::endl;
}

double SalesPerson::totalAnnualSales() const {
    double total{0.0};

    for (int i{0}; i < monthsPerYear; ++i) {
        total += sales[i];
    }

    return total;
}
