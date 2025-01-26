#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include "Inventory.h"

class InventorySystem {
public:
	// Constructor and Destructor
	InventorySystem();
	~InventorySystem();

	// Run the system
	void run();

private:
	Inventory inventory;

	// Helper function to display menu options
	void displayMenu() const;
};



#endif //INVENTORYSYSTEM_H
