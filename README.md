### README for the OOP Project: "Perfume Store Inventory Management System with Online and In-Store Sales"

#### Project Overview
This project is an enhanced version of a C++ application designed to simulate an inventory management system for a perfume store. It includes the management of perfumes, employees, sales (both online and in-store), and store inventory through various functionalities like creating, reading, updating, and deleting records. The project also demonstrates advanced OOP concepts like virtual functions, inheritance, and polymorphism.

#### Classes Overview

1. **Produs (Product)**: 
   - An abstract base class that defines the common interface for products, such as `getNumeProdus`, `getPret`, and `afisareDetalii`.
   - All derived classes must implement these pure virtual functions.

2. **Parfum (Perfume)**: 
   - A derived class from `Produs` that represents a perfume with additional attributes like `idParfum`, `brand`, `rating`, `tipAroma`, availability (`inStoc`), and price.
   - Implements the virtual methods from `Produs` and provides functionalities like displaying perfume details, determining the best sales season (`perioadaDeVarf`), and supporting various operator overloads.

3. **Angajat (Employee)**: 
   - Represents an employee with attributes such as `idAngajat`, `nume`, `post`, employment status (`inActivitate`), and salary.
   - Contains functionality to estimate future salary growth (`salariuEstimat`) and includes operator overloading.

4. **Vanzare (Sale)**: 
   - The base class for representing a sale, containing attributes like `idVanzare`, `idAngajat`, `numeClient`, `sumaTotala`, `numarAchizitii`, and a list of purchased perfume IDs.
   - This class is further extended by `VanzareOnline` and `VanzareInMagazin` to provide specific functionalities for each sale type.
   - The class also provides methods like `parfumCumparat` to check if specific perfumes are part of a sale.

5. **VanzareOnline (Online Sale)**:
   - A derived class from `Vanzare` that adds attributes specific to online sales, such as `adresaLivrare` (delivery address), `modalitPlata` (payment method), and `dataComanda` (order date).
   - Implements additional functionality like calculating a discount based on payment method (`calculDiscount`) and estimating delivery time.

6. **VanzareInMagazin (In-Store Sale)**:
   - A derived class from `Vanzare` and `InventarMagazin` that represents in-store sales.
   - Adds attributes such as `clientFidel` (loyal customer) and `testereGratuite` (free samples) and provides functionality like checking if a sale cannot proceed due to stock shortages (`outOfStock`).

7. **InventarMagazin (Store Inventory)**:
   - Manages the store's inventory of perfumes, keeping track of the number of perfume types, the stock for each, and the total profit.
   - Provides functionality to check the number of units in stock for a particular perfume (`bucatiInventar`).

#### Key Features

- **Multiple Sale Types**: The system supports both online and in-store sales, each with specific attributes and methods.
- **CRUD Operations**: Users can create, read, update, and delete instances of perfumes, employees, sales, and inventory.
- **Discount Calculation**: For online sales, discounts can be calculated based on the payment method.
- **Stock Management**: The system allows users to track and manage the store's perfume inventory, including checking for out-of-stock items.
- **Salary Estimation**: Calculates potential salary growth for employees based on a monthly increment.
  
#### Operator Overloading and Polymorphism
Each class supports several operator overloads for comparison, assignment, indexing, and arithmetic operations. For example:
- `Parfum operator=(const Parfum &)` allows assignment between perfumes.
- `Vanzare &operator--()` reduces the total sum and number of items in a sale.
- `VanzareOnline::asteptareComanda()` and `VanzareInMagazin::asteptareComanda()` demonstrate polymorphism, where each class calculates waiting time differently.

#### Virtual Functions
The use of pure virtual functions in the `Produs` and `Vanzare` classes allows for runtime polymorphism, enabling the program to handle different types of sales (online and in-store) with shared interfaces.

#### User Interaction
The program is interactive, providing a menu-driven interface for users to:
1. Create new records for perfumes, employees, sales, and inventories.
2. Read existing records and view details for each object.
3. Update records for perfumes, employees, sales, and inventories.
4. Delete records.
5. Execute specific functionalities like estimating salaries, managing stock, or applying discounts for online sales.

#### Sample Menu Options
The menu system allows the user to:
- Choose between creating, reading, updating, or deleting objects (perfumes, employees, sales, inventories).
- Execute additional functionalities, such as:
  - Displaying the best sales season for perfumes.
  - Estimating future employee salaries based on their current salary and monthly raise.
  - Calculating discounts for online sales or checking if in-store sales cannot proceed due to out-of-stock items.

#### Usage
To run the program, compile and execute the code. You will be presented with a menu from which you can select the desired operations. The menu is interactive and allows for the full management of the store's inventory and sales.

#### Future Improvements
- **File Persistence**: Add the ability to save and load records to/from files so that data is persistent between sessions.
- **Enhanced User Interface**: Consider adding a graphical user interface (GUI) to improve user interaction.
- **Advanced Error Handling**: Implement more robust error handling for invalid user inputs.
  
This project demonstrates advanced object-oriented programming (OOP) concepts such as inheritance, polymorphism, operator overloading, and virtual functions.
