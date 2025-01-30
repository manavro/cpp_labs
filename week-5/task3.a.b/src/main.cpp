#include <iostream>
#include <string>
#include <iomanip>
#include "SensorData.h"

int main() {
    std::string input;
    SensorData sensorData[MAX_SENSORS];
    int sensorCount = 0;

    try {
        std::cout << "Enter a batch of sensor readings (maximum 512 characters): ";
        std::getline(std::cin, input);

        if (input.length() > 512) {
            throw std::length_error("Error: String length exceeds 512 characters.");
        }

        calculateAverageTemperatures(input, sensorData, sensorCount);

        int sortField;
        std::cout << "Enter 1 to sort by ID, 2 to sort by average temperature: ";
        std::cin >> sortField;

        if (sortField == 1) {
            sortById(sensorData, sensorCount);
        }
        else if (sortField == 2) {
            sortByAverageTemperature(sensorData, sensorCount);
        }
        else {
            throw std::invalid_argument("Error: incorrect sort selection.");
        }

        std::cout << std::fixed << std::setprecision(1);
        for (int i = 0; i < sensorCount; ++i) {
            if (sensorData[i].count == 0) {
                throw std::runtime_error("Error: Division by zero - count cannot be zero.");
            }
            double averageTemperature = sensorData[i].totalTemperature / sensorData[i].count;
            std::cout << sensorData[i].id << " " << averageTemperature << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}