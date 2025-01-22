#ifndef SALESPERSON_H
#define SALESPERSON_H

class SalesPerson {
public:
    static const int monthsPerYear = 12;
    SalesPerson();
    void getSalesFromUser();
    void setSales(int, double);
    void printAnnualSales() const;

private:
    [[nodiscard]] double totalAnnualSales() const;
    double sales[monthsPerYear]{};
};

#endif //SALESPERSON_H
