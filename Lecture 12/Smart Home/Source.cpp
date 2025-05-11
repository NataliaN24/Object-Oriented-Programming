#include "SmartLight.h"
#include "SmartSpeaker.h"
#include "SmartThermostat.h"
#include "SmartHome.h"

int main() {
    SmartHome home;

    SmartLight light(MyString("Ceiling Light"), MyString("Philips"), 150, 80);
    SmartSpeaker speaker(MyString("Echo Dot"), MyString("Amazon"), 120, 70);
    SmartThermostat thermostat(MyString("Nest"), MyString("Google"), 200, 21, 24);

    home.addDevice(light);
    home.addDevice(speaker);
    home.addDevice(thermostat);

    std::cout << "\n--- All Devices ---\n";
    home.print();

    std::cout << "\n--- Turning On Device at index 1 ---\n";
    home.turnOn(1, *home[1]);

    std::cout << "\n--- Turning Off Device at index 0 ---\n";
    home.turnOff(0, *home[0]);

    std::cout << "\n--- Average Price for 'Google' Devices ---\n";
    std::cout << home.getAverage(MyString("Google")) << std::endl;

    std::cout << "\n--- Removing Device at index 1 ---\n";
    home.removeDevice(1);

    std::cout << "\n--- All Devices After Removal ---\n";
    home.print();

    return 0;
}
