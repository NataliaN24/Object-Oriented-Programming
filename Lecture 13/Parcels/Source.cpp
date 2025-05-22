#include <iostream>
#include "LandOwner.h"

int main() {
    LandOwner owner;

    int numParcels;
    std::cout << "How many parcels do you want to add? ";
    std::cin >> numParcels;

    for (int i = 0; i < numParcels; ++i) {
        char str[32];
        std::cout << "\nEnter parcel type (CircleParcel / RectangleParcel / TriangleParcel): ";
        std::cin >> str;

        Parcel* p = factory(str); 

        if (p != nullptr) {
            owner.addParcel(*p); 
            delete p;
        }
        else {
            std::cout << "Invalid parcel type!\n";
        }
    }

    std::cout << "\n=== Result ===\n";
    std::cout << "Total area: " << owner.getTotalArea() << std::endl;
    std::cout << "Total perimeter: " << owner.getTotalPerimeter() << std::endl;

    return 0;
}
