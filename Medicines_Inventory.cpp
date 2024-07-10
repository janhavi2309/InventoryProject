#include <iostream>
#include <string>

const int MAX_MEDICINES = 100;

struct Medicine {
    std::string name;
    double price;
    int quantity;
};

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount < MAX_MEDICINES) {
        std::cout << "Enter medicine name: ";
        std::cin >> inventory[medicineCount].name;
        std::cout << "Enter price: ";
        std::cin >> inventory[medicineCount].price;
        std::cout<<"Enter medicine quantity: ";
        std::cin>> inventory[medicineCount].quantity;
        medicineCount++;
        std::cout << "Medicine added.\n";
    } else {
        std::cout << "Inventory full.\n";
    }
}

void viewPrice() {
    std::string name;
    std::cout << "Enter medicine name: ";
    std::cin >> name;
    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].name == name) {
            std::cout << "Price of " << name << ": ₹" << inventory[i].price << "\n";
            return;
        }
    }
    std::cout << "Medicine not found.\n";
}

void displayInventory() {
    if (medicineCount == 0) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    std::cout << "Inventory:\n";
    for (int i = 0; i < medicineCount; i++) {
        std::cout <<"Medicine Name: "<< inventory[i].name;
        std::cout<<"\nPrice: ₹"<< inventory[i].price;
        std::cout<<"\nQuantity available: "<< inventory[i].quantity<<"\n";
    }
}

void deleteMedicine() {
    std::string name;
    std::cout << "Enter medicine name to delete: ";
    std::cin >> name;
    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].name == name) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            std::cout << "Medicine deleted.\n";
            return;
        }
    }
    std::cout << "Medicine not found.\n";
}

int main() {
    while (true) {
        std::cout << "\n1. Add Medicine\n2. View Price\n3. Display Inventory\n"<< "4. Delete Medicine\n5. Exit\nChoice: ";
                 
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewPrice(); break;
            case 3: displayInventory(); break;
            case 4: deleteMedicine(); break;
            case 5: return 0;
            default: std::cout << "Invalid choice.\n";
        }
    }
}