# Vending Machine (C++)

## Design Patterns:
- **Singleton Pattern**
- **State Pattern**
## Design Patterns:
- **Singleton Pattern**
- **State Pattern**

## Commits:

**1. [FEAT] : Initial Commit**

**2. [FEAT] : Demo setup**
-   **File Created**: `main.cpp`.
-   **Details**: Implement a basic `main` function that prints a "Hello Vending Machine" message to verify the build system is working correctly.
-   **Branching**: Create a `dev` branch for ongoing development work.

---

**3. [FIX] : updates the development plan**
-   **File Updated**: `development.md`.
-   **Details**: Refine the development plan with more specific steps and low-level details for each upcoming feature commit.

---

**4. [FEAT] : adds Item header and implementation**
-   **Files Created**: `Item.h`, `Item.cpp`.
-   **Class**: `Item`
    -   **Data Members (private)**:
        -   `std::string code_`
        -   `std::string name_`
        -   `int price_`
    -   **Methods (public)**:
        -   Constructor: `Item(const std::string& code, const std::string& name, int price)`
        -   `std::string getCode() const`
        -   `std::string getName() const`
        -   `int getPrice() const`

---

**5. [FEAT] : adds Inventory header and implementation**
-   **Files Created**: `Inventory.h`, `Inventory.cpp`.
-   **Class**: `Inventory`
    -   **Data Members (private)**:
        -   `std::unordered_map<std::string, std::unique_ptr<Item>> itemMap_`
        -   `std::unordered_map<std::string, int> stockMap_`
    -   **Methods (public)**:
        -   `void addItem(const std::string& code, const std::string& name, int price, int quantity)`
        -   `Item* getItem(const std::string& code)`
        -   `bool isAvailable(const std::string& code) const`
        -   `void reduceStock(const std::string& code)`

---

**6. [FEAT] : adds Coin enum**
-   **File Created**: `Coin.h`.
-   **Enum Class**: `enum class Coin : int`
    -   **Values**: `PENNY = 1`, `NICKEL = 5`, `DIME = 10`, `QUARTER = 25`.
-   **Details**: Provides a type-safe enumeration for coin denominations. No `.cpp` file is needed.

---

**7. [FEAT] : adds vending machine state interface and vending machine interface**
-   **File 1 Created**: `VendingMachineState.h`
    -   **Class**: `VendingMachineState` (Abstract Base Class)
    -   **Methods (public)**:
        -   `virtual ~VendingMachineState() = default;` (Virtual Destructor)
        -   `virtual void insertCoin(...) = 0;` (Pure Virtual Function)
        -   `virtual void selectItem(...) = 0;` (Pure Virtual Function)
        -   `virtual void dispense(...) = 0;` (Pure Virtual Function)
        -   `virtual void refund(...) = 0;` (Pure Virtual Function)
-   **File 2 Created**: `VendingMachine.h`
    -   **Class**: `VendingMachine` (Singleton Context Class)
    -   **Data Members (private)**:
        -   `std::unique_ptr<Inventory> inventory_`
        -   `std::unique_ptr<VendingMachineState> currentState_`
        -   `int balance_`
        -   `std::string selectedItemCode_`
    -   **Methods (public)**:
        -   `static VendingMachine& getInstance()`
        -   Delegation methods: `insertCoin(Coin coin)`, `selectItem(const std::string& code)`, etc.
        -   Methods for States: `setState(...)`, `getInventory()`, `getSelectedItem()`, `addBalance(...)`, etc.
    -   **Methods (private)**:
        -   `VendingMachine()` (Private Constructor)
        -   Deleted copy constructor and copy assignment operator.

**8. [FEAT] : adds all state interfaces**
-   **Files Created**:
    -   `IdleState.h`
    -   `ItemSelectedState.h`
    -   `HasMoneyState.h`
    -   `DispensingState.h`
-   **Class `IdleState`**: Handles the initial state. `selectItem` transitions to `ItemSelectedState`.
-   **Class `ItemSelectedState`**: Handles coin insertion. Transitions to `HasMoneyState` when balance is sufficient or `IdleState` on refund.
-   **Class `HasMoneyState`**: Handles dispense action. `dispense` transitions to `DispensingState`.
-   **Class `DispensingState`**: A transient state that blocks user actions while the machine is physically dispensing.
