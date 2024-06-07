#pragma once
#include "pch.h"
#include "Sensor.h"

namespace rbr {
    class PressureSensor : public Sensor {
    public:
        PressureSensor(int id);

        std::string generateData() const override;
    };
}