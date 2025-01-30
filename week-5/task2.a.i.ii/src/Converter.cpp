#include "Converter.h"
#include <stdexcept>

int convert_to_int(const std::string& input_str) {
    try {
        return std::stoi(input_str);
    }
    catch (const std::invalid_argument&) {
        throw std::invalid_argument("Cannot convert to integer.");
    }
    catch (const std::out_of_range&) {
        throw std::out_of_range("Number is out of range for integers.");
    }
}

double convert_to_float(const std::string& input_str) {
    try {
        return std::stod(input_str);
    }
    catch (const std::invalid_argument&) {
        throw std::invalid_argument("Cannot convert to floating point.");
    }
    catch (const std::out_of_range&) {
        throw std::out_of_range("Number is out of range for floating point numbers.");
    }
}

std::string convert_to_str(const std::string& input_str) {
    return input_str;
}
