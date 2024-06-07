#pragma once
#include "pch.h"
#include "TempratureSensor.h"
#include "PressureSensor.h"
#include "ConductivitySensor.h"

namespace rbr {

    class SensorManager {
    private:
        std::map<int, std::unique_ptr<Sensor>> m_sensors;
        int nextId;

    public:
        SensorManager();
        ~SensorManager();

        bool addSensor(const std::string& type);
        bool listSensors() const;
        bool removeSensor(int id);
    };
}
