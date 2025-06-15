#include "Store.h"
#include "Laptop.h"
#include "Computer.h"

int main() {
    // Get the singleton store instance
    Store& store = Store::getInstance();

    // Create some gadgets (computers and laptops)
    Laptop* lenovo = new Laptop("Lenovo", 1299.99, 2.1);
    Computer* hp = new Computer("HP Desktop", 899.99);

    // Buy products (add them to the store)
    store.buyProduct(*lenovo);
    store.buyProduct(*hp);

    std::cout << "All products in the store:\n";
    for (auto it = store.begin(); it != store.end(); ++it) {
        (*it)->print();
        std::cout << std::endl;
    }

    // Sell a product (remove it from the store)
    store.sellProduct(*lenovo);

    std::cout << "\nAfter selling the Lenovo laptop:\n";
    for (auto it = store.begin(); it != store.end(); ++it) {
        (*it)->print();
        std::cout << std::endl;
    }

    // Clean up manually allocated memory
    delete lenovo;
    delete hp;

    return 0;
}
