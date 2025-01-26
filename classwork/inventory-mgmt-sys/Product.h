#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    // Constructors
    Product(int id, const std::string& name, const std::string& description, double price, int quantity);
    Product(const Product& other); // Copy constructor
    ~Product(); // Destructor

    // Getters
    int getProductID() const;
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setPrice(double price);
    void setQuantity(int quantity);

    // Display function
    void display() const;

    // Assignment operator
    Product& operator=(const Product& other);

private:
    int productID;
    std::string name;
    std::string description;
    double price;
    int quantity;
};

#endif //PRODUCT_H
