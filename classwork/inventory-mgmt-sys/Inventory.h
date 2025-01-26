#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Product.h"

class Inventory {
public:
	// Constructor and Destructor
	Inventory();
	~Inventory();

	// Operations
	void addProduct(const Product& product);
	void removeProduct(int productID);
	void updateProductQuantity(int productID, int newQuantity);
	void updateProductDetails(int productID, const std::string& name, const std::string& description, double price);
	void displayAllProducts() const;
	bool isEmpty() const;

	// Search
	Product* findProductByID(int productID);

private:
	std::vector<Product> products;

	// Helper function to find a product by ID
	int findProductIndex(int productID) const;
};

#endif //INVENTORY_H
