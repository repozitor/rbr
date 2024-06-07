#pragma once
#include "pch.h"
#include "Sensor.h"

namespace rbr {
    class ConductivitySensor : public Sensor {
    public:
        ConductivitySensor(int id);

        std::string generateData() const override;
    };
}