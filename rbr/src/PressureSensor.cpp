#include "pch.h"
#include "PressureSensor.h"

using namespace rbr;

PressureSensor::PressureSensor(int id) :
    Sensor(id, 1)
{
}

std::string PressureSensor::generateData() const {
    return "Pressure\t Value: N/A";
}