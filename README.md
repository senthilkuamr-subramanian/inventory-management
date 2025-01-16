# Inventory Management System

A simple console-based Inventory Management System written in C++ to help manage products, including adding, viewing, searching, and selling items.

## Features
- **Add Item**: Add new items with a unique ID, name, quantity, and price per unit.
- **View Items**: Display all items in a tabular format, including total price (quantity * unit price).
- **Search Item**: Search for an item by its name.
- **Sell Item**: Update the quantity of an item when it gets sold.
- **Total Price Calculation**: Automatically calculates and displays the total price of items based on quantity and unit price.

## How to Use
1. Clone the repository or copy the source code.
2. Compile the code using a C++ compiler (e.g., g++):
   ```bash
   g++ inventory_management.cpp -o inventory_management
   ```
3. Run the application:
   ```bash
   ./inventory_management
   ```
4. Follow the menu options to:
   - Add new items.
   - View the inventory.
   - Search for specific items.
   - Sell items and update their quantities.

## Menu Options
1. **Add Item**: Enter the name, quantity, and price per unit of the item.
2. **View Items**: Displays all items in a table with ID, name, quantity, unit price, and total price.
3. **Search Item**: Find items by name.
4. **Sell Item**: Deduct sold quantity from the inventory.
5. **Exit**: Close the application.

## Example Output
```
Inventory Management System
1. Add Item
2. View Items
3. Search Item
4. Sell Item
5. Exit
Enter your choice: 1

Enter item name: Laptop
Enter quantity: 10
Enter price per unit: 800.50
Item added successfully!

Inventory Management System
1. Add Item
2. View Items
3. Search Item
4. Sell Item
5. Exit
Enter your choice: 2

ID        Name                 Quantity  Unit Price     Total Price   
---------------------------------------------------------------------
1         Laptop               10        $800.50        $8005.00
```

## Requirements
- C++ compiler (supports C++11 or later).

## Project Structure
- **`inventory_management.cpp`**: Main source code for the Inventory Management System.

## Future Improvements
- Add file storage to save inventory data between sessions.
- Include user authentication for secure access.
- Add support for editing item details (e.g., name or price).
- Enhance the UI for better usability.

## License
This project is open-source and available under the [MIT License](LICENSE).

---
Feel free to fork, modify, and use this project for personal or educational purposes. Contributions are welcome!

