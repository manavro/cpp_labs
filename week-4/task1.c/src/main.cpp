#include <iostream>
#include <string>
#include <iomanip>
#include "SensorData.h"

int main() {
    std::string input;
    SensorData sensorData[MAX_SENSORS];
    int sensorCount = 0;

    std::cout << "Enter a batch of sensor readings (maximum 512 characters): ";
    std::getline(std::cin, input);

    if (input.length() > 512) {
        std::cerr << "Error: String length exceeds 512 characters." << std::endl;
        return 1;
    }

    calculateAverageTemperatures(input, sensorData, sensorCount);

    int sortField;
    std::cout << "Enter 1 to sort by ID, 2 to sort by average temperature : ";
    std::cin >> sortField;

    if (sortField == 1) {
        sortById(sensorData, sensorCount);
    }
    else if (sortField == 2) {
        sortByAverageTemperature(sensorData, sensorCount);
    }
    else {
        std::cerr << "Error: incorrect sort selection." << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < sensorCount; ++i) {
        double averageTemperature = sensorData[i].totalTemperature / sensorData[i].count;
        std::cout << sensorData[i].id << " " << averageTemperature << std::endl;
    }

    return 0;
}