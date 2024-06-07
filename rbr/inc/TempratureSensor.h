#pragma once
#include "pch.h"
#include "Sensor.h"

namespace rbr {
    class TempratureSensor : public Sensor {
    public:
        TempratureSensor(int id);

        std::string generateData() const override;
    };
}