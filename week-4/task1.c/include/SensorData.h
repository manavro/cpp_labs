#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <string>

const int MAX_SENSORS = 100;

struct SensorData {
    int id;
    double totalTemperature;
    int count;

    SensorData();
};

void calculateAverageTemperatures(const std::string& input, SensorData sensorData[], int& sensorCount);
void sortById(SensorData sensorData[], int sensorCount);
void sortByAverageTemperature(SensorData sensorData[], int sensorCount);

#endif SENSORDATA_H
