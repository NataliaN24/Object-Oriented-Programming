#include <iostream>
#include "TPeak.h"
#include "MPeak.h"
#include "Collection.h"
#include "Factory.h"

int main() {
    Collection peaks;

    // Create TPeak and MPeak manually
    TPeak t1("Rila", 2925, "Musala");
    MPeak m1("Pirin", 2914, 42.0);

    // Add to collection
    peaks.addPeak(t1);
    peaks.addPeak(m1);

    std::cout << "Initial peaks in collection:\n";
    peaks.printPeaks(); // Should print: TpeakMpeak (on same line)

    //std::cout << "\n";

    //// Test polymorphic proximity logic
    //Peak* p1 = new TPeak("Stara Planina", 2376, "Botev");
    //Peak* p2 = new MPeak("Vitosha", 2290, 12.0);

    //std::cout << "Are p1 and p2 near? (calls double dispatch):\n";
    //std::cout << (p1->twoPeaksNear(p2) ? "Yes" : "No") << "\n";

    //delete p1;
    //delete p2;

    return 0;
}
