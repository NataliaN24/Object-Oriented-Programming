#include <iostream>
#include "FoodPanda.h"
#include "Product.h"
#include "Order.h"

int main() {
    try {
        
        Product pizza(MyString("Pizza"));
        Product burger(MyString("Burger"));
        Product pasta(MyString("Pasta"));

        Product products[] = { pizza, burger };

        Restaurant restaurant("Good Eats", products, 2);

        
        FoodPanda foodPanda;
        foodPanda.addRestaurant(restaurant);

        Product orderProducts[] = { pizza, burger }; 
        Order order("Good Eats", 2, orderProducts);

        foodPanda.addOrder(order, restaurant);
        std::cout << "Order placed successfully!" << std::endl;

        Product invalidProduct(MyString("Sushi"));
        Product invalidOrderProducts[] = { pizza, invalidProduct }; 
        Order invalidOrder("Good Eats", 2, invalidOrderProducts);

        foodPanda.addOrder(invalidOrder, restaurant);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl; 
    }
    catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;  
    }

    return 0;
}