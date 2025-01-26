#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    // Constructor
    Product(const std::string &name, const std::string &description, double price, int quantity);

    // Destructor
    ~Product();

    // Getters
    int getID() const;
    std::string getInfo() const;

    // Setters
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);

private:
    int prod_id;
    std::string prod_name;
    std::string prod_desc;
    double prod_price;
    int prod_quantity{1};
    static int next_id;
};

#endif //PRODUCT_H
