#include "Restaurant.h"
#include "Food.h"
#include "Drink.h"
#include <iostream>

int main() {
    Restaurant restaurant;

    restaurant.addProduct(new Food(productType::food, 10, 5.50, "Burger", 300));
    restaurant.addProduct(new Food(productType::food, 5, 7.20, "Pasta", 250));

    restaurant.addProduct(new Drink(productType::drink, 20, 2.00, "Cola", 0.0));  // Non-alcoholic
    restaurant.addProduct(new Drink(productType::drink, 10, 3.50, "Beer", 5.0));  // Alcoholic
    restaurant.addProduct(new Drink(productType::drink, 15, 1.50, "Water", 0.0)); // Non-alcoholic

    std::cout << "=== All Items ===\n";
    restaurant.printAll();

    std::cout << "\n=== Non-Alcoholic Drinks ===\n";
    restaurant.printAllNonAlcohol();

    return 0;
}
