#pragma once

#include <iostream>
#include <string>

namespace satl {
    void converter(double value, std::string &type);
    bool isInt(const std::string &num);
    bool isFloat(const std::string &num);
}