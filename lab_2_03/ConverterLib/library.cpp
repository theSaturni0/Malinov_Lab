#include "library.h"

#include <algorithm>

namespace satl {
    void converter(const double value, std::string &type) {

        std::transform(type.begin(), type.end(), type.begin(),
                   [](unsigned char c) { return std::tolower(c); });
        double baseValue;

        // Temperature [ SPECIAL CASE !! ]

        if (type == "celsius") {
            std::cout << value << " Celsius\n";
            std::cout << (value * 1.8 + 32) << " Fahrenheit\n";
            std::cout << (value + 273.15) << " Kelvin\n";
        } else if (type == "fahrenheit") {
            std::cout << ((value - 32) / 1.8) << " Celsius\n";
            std::cout << value << " Fahrenheit\n";
            std::cout << (((value - 32) * 1.8) + 273.15) << " Kelvin\n";
        } else if (type == "kelvin") {
            std::cout << (value - 273.15) << " Celsius\n";
            std::cout << ((value - 273.15) * 1.8 + 32) << " Fahrenheit\n";
            std::cout << value << " Kelvin\n";

        // Length

        } else if (type == "meters" || type == "kilometers" || type == "miles" || type == "feet") {
            if (type == "meters") baseValue = value;
            else if (type == "kilometers") baseValue = value * 1000.0;
            else if (type == "miles") baseValue = value * 1609.34;
            else if (type == "feet") baseValue = value * 0.3048;

            std::cout << baseValue << " Meters\n";
            std::cout << (baseValue / 1000.0) << " Kilometers\n";
            std::cout << (baseValue / 1609.34) << " Miles\n";
            std::cout << (baseValue / 0.3048) << " Feet\n";

        // Mass

        } else if (type == "kilograms" || type == "grams" || type == "pounds") {
            if (type == "kilograms") baseValue = value;
            else if (type == "grams") baseValue = value / 1000.0;
            else if (type == "pounds") baseValue = value * 0.453592;

            std::cout << baseValue << " Kilograms\n";
            std::cout << (baseValue * 1000) << " Grams\n";
            std::cout << (baseValue / 0.453592) << " Pounds\n";

        // Time

        } else if (type == "seconds" || type == "minutes" || type == "hours") {
            if (type == "seconds") baseValue = value;
            else if (type == "minutes") baseValue = value * 60.0;
            else if (type == "hours") baseValue = value * 3600.0;

            std::cout << baseValue << " Seconds\n";
            std::cout << (baseValue / 60.0) << " Minutes\n";
            std::cout << (baseValue / 3600.0) << " Hours\n";

        // Volume

        } else if (type == "liters" || type == "milliliters" || type == "gallons") {
            if (type == "liters") baseValue = value;
            else if (type == "milliliters") baseValue = value / 1000.0;
            else if (type == "gallons") baseValue = value * 3.78541;

            std::cout << baseValue << " Liters\n";
            std::cout << (baseValue * 1000) << " Milliliters\n";
            std::cout << (baseValue / 3.78541) << " Gallons\n";
        }
        else {
            std::cout << "Unknown unit type: " << type << "\n";
        }
    }

    bool isInt(const std::string &num) {
        if (num.empty()) { return false; }

        int start = 0;

        if (num[0] == '0' && num.length() != 1) { return false; }

        if (num[0] == '-') {
            if (num.length() == 1) { return false; }
            start = 1;
        }

        for (int i = start; i < num.length(); i++) {
            if (num[i] < '0' || num[i] > '9') { return false; }
        }

        return true;
    }

    bool isFloat(const std::string &num) {
        if (num.empty()) { return false; }

        int start = 0;
        bool decimal = false;

        if (num[0] == '-') {
            if (num.length() == 1) { return false; }
            start = 1;
        }

        if (num[0] == '0' && num.length() != 1) { return false; }
        if (num[start] == '.' || num[num.length()-1] == '.') { return false; }

        for (int i = start; i < num.length(); i++) {
            if (num[i] == '.') {
                if (decimal) { return false; }
                decimal = true;
                continue;
            }
            if (num[i] < '0' || num[i] > '9') { return false; }
        }

        return true;
    }
}
