#include "pch.h"
#include "ConductivitySensor.h"

using namespace rbr;

ConductivitySensor::ConductivitySensor(int id) :
    Sensor(id, 16)
{
}

std::string ConductivitySensor::generateData() const {
    return "Conductivity\t Value: N/A";
}