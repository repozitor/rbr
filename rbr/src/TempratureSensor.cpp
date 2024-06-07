#include "pch.h"
#include "TempratureSensor.h"

using namespace rbr;

TempratureSensor::TempratureSensor(int id) :
    Sensor(id, 8)
{
}

std::string TempratureSensor::generateData() const {
    return "Temprature\t Value: N/A";
}