#include <iostream>
#include <vector>

using namespace std;

class GroceryProduct {
private:
    int productID, price;
    string productName;

public:
    GroceryProduct(int id, string name, int price) {
        this->productID = id;
        this->productName = name;
        this->price = price;
    }

    void viewProductDetails() {
        cout << "\n===========================\n";
        cout << "Product ID   : " << productID << "\n";
        cout << "Product Name : " << productName << "\n";
        cout << "Price        : Rs. " << price << "\n";
        cout << "===========================\n";
    }

    int getProductId() {
        return productID;
    }

    void updateProduct(string newName, int newPrice) {
        productName = newName;
        price = newPrice;
        cout << "\n✔ Product updated successfully!\n";
    }
};

int main() {
    vector<GroceryProduct> inventory;
    int choice;

    cout << "\n===== Grocery Inventory System =====\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Product\n";
        cout << "2. View All Products\n";
        cout << "3. Remove Product\n";
        cout << "4. Update Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, price;
                string name;

                cout << "Enter Product ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Product Name: ";
                getline(cin, name);
                cout << "Enter Product Price: ";
                cin >> price;

                GroceryProduct newProduct(id, name, price);
                inventory.push_back(newProduct);

                cout << "\n✔ Product added successfully!\n";
                break;
            }

            case 2: {
                if (inventory.empty()) {
                    cout << "\n Inventory is empty!\n";
                } else {
                    cout << "\n Product List:\n";
                    for (auto& product : inventory) {
                        product.viewProductDetails();
                    }
                }
                break;
            }

            case 3: {
                if (inventory.empty()) {
                    cout << "\n⚠ Inventory is empty!\n";
                    break;
                }

                int id;
                cout << "Enter Product ID to remove: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < inventory.size(); i++) {
                    if (inventory[i].getProductId() == id) {
                        inventory.erase(inventory.begin() + i);
                        cout << "\n✔ Product removed successfully!\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\n Product not found.\n";
                }
                break;
            }

            case 4: {
                if (inventory.empty()) {
                    cout << "\n⚠ Inventory is empty!\n";
                    break;
                }

                int id, newPrice;
                string newName;

                cout << "Enter Product ID to update: ";
                cin >> id;
                cin.ignore();

                bool found = false;
                for (int i = 0; i < inventory.size(); i++) {
                    if (inventory[i].getProductId() == id) {
                        cout << "Enter New Product Name: ";
                        getline(cin, newName);
                        cout << "Enter New Product Price: ";
                        cin >> newPrice;

                        inventory[i].updateProduct(newName, newPrice);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\nProduct not found.\n";
                }
                break;
            }

            case 5: {
                cout << "\n Exiting program. Thank you!\n";
                break;
            }

            default:
                cout << "\n Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}