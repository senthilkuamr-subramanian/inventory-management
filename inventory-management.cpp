#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

class Inventory {
private:
    vector<Item> items;
    int nextId = 1;

public:
    void addItem() {
        Item newItem;
        newItem.id = nextId++;

        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, newItem.name);

        cout << "Enter quantity: ";
        cin >> newItem.quantity;

        cout << "Enter price per unit: ";
        cin >> newItem.price;

        items.push_back(newItem);
        cout << "Item added successfully!\n";
    }

    void viewItems() const {
        if (items.empty()) {
            cout << "No items in the inventory.\n";
            return;
        }

        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Quantity" << setw(15) << "Unit Price" << setw(15) << "Total Price" << endl;
        cout << string(70, '-') << endl;
        for (const auto &item : items) {
            cout << left << setw(10) << item.id
                 << setw(20) << item.name
                 << setw(10) << item.quantity
                 << "$" << fixed << setprecision(2) << item.price
                 << "$" << fixed << setprecision(2) << (item.price * item.quantity) << endl;
        }
    }

    void searchItem() const {
        if (items.empty()) {
            cout << "No items in the inventory to search.\n";
            return;
        }

        string searchName;
        cout << "Enter the name of the item to search: ";
        cin.ignore();
        getline(cin, searchName);

        bool found = false;
        for (const auto &item : items) {
            if (item.name == searchName) {
                cout << "Item found:\n";
                cout << "ID: " << item.id << ", Name: " << item.name
                     << ", Quantity: " << item.quantity << ", Unit Price: $"
                     << fixed << setprecision(2) << item.price
                     << ", Total Price: $" << (item.price * item.quantity) << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found in the inventory.\n";
        }
    }

    void sellItem() {
        if (items.empty()) {
            cout << "No items in the inventory to sell.\n";
            return;
        }

        int itemId;
        int sellQuantity;

        cout << "Enter the ID of the item to sell: ";
        cin >> itemId;

        auto it = find_if(items.begin(), items.end(), [itemId](const Item &item) {
            return item.id == itemId;
        });

        if (it != items.end()) {
            cout << "Enter quantity to sell: ";
            cin >> sellQuantity;

            if (sellQuantity > it->quantity) {
                cout << "Not enough quantity available to sell.\n";
            } else {
                it->quantity -= sellQuantity;
                cout << "Sold " << sellQuantity << " of " << it->name << ". Remaining quantity: " << it->quantity << "\n";
            }
        } else {
            cout << "Item with ID " << itemId << " not found.\n";
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Search Item\n";
        cout << "4. Sell Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inventory.addItem();
            break;
        case 2:
            inventory.viewItems();
            break;
        case 3:
            inventory.searchItem();
            break;
        case 4:
            inventory.sellItem();
            break;
        case 5:
            cout << "Exiting the application. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
