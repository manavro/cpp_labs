#include "SensorData.h"
#include <sstream>
#include <iostream>
#include <algorithm>

SensorData::SensorData() : id(0), totalTemperature(0.0), count(0) {}

void calculateAverageTemperatures(const std::string& input, SensorData sensorData[], int& sensorCount) {
    std::stringstream ss(input);
    std::string token;

    
    while (std::getline(ss, token, '@')) {
        if (token.length() < 4) {
            std::cerr << "Error: incorrect data format." << std::endl;
            return;
        }

        
        int id = std::stoi(token.substr(0, 2));
        int temperature = std::stoi(token.substr(2));

        
        bool found = false;
        for (int i = 0; i < sensorCount; ++i) {
            if (sensorData[i].id == id) {
                sensorData[i].totalTemperature += temperature;
                sensorData[i].count++;
                found = true;
                break;
            }
        }

        
        if (!found && sensorCount < MAX_SENSORS) {
            sensorData[sensorCount].id = id;
            sensorData[sensorCount].totalTemperature = temperature;
            sensorData[sensorCount].count = 1;
            sensorCount++;
        }
    }
}

void sortById(SensorData sensorData[], int sensorCount) {
    std::sort(sensorData, sensorData + sensorCount, [](const SensorData& a, const SensorData& b) {
        return a.id < b.id;
        });
}

void sortByAverageTemperature(SensorData sensorData[], int sensorCount) {
    std::sort(sensorData, sensorData + sensorCount, [](const SensorData& a, const SensorData& b) {
        return (a.totalTemperature / a.count) < (b.totalTemperature / b.count);
        });
}