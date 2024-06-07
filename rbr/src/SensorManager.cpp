#include "pch.h"
#include "SensorManager.h"

using namespace rbr;

SensorManager::SensorManager() :
    nextId(0)
{
}

SensorManager::~SensorManager()
{
}

bool SensorManager::addSensor(const std::string& type)
{
    if (type == "pressure" || type == "p")
    {
        m_sensors[nextId] = std::make_unique<PressureSensor>(nextId);
    }
    else if (type == "temperature" || type == "t")
    {
        m_sensors[nextId] = std::make_unique<TempratureSensor>(nextId);
    }
    else if (type == "conductivity" || type == "c")
    {
        m_sensors[nextId] = std::make_unique<ConductivitySensor>(nextId);
    }
    else
    {
        std::cout << "Invalid sensor type: " << type << std::endl;
        return false;
    }
    std::cout << "Sensor " << nextId << " added." << std::endl;
    nextId++;

    return true;
}

bool SensorManager::listSensors() const {
    try
    {
        std::cout << "List of available sensors" << std::endl;
        if (m_sensors.size() == 0)
        {
            std::cout << "No sensor found" << std::endl;
        }
        for (const auto& [id, sensor] : m_sensors) {
            std::cout << "Sensor Id: " << id << std::endl;
        }
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unable to list sensors reason: " << e.what();
        return false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << std::endl;
        return false;
    }
}

bool SensorManager::removeSensor(int id) {
    try
    {
        if (m_sensors.erase(id)) {
            std::cout << "Sensor " << id << " removed." << std::endl;
        }
        else {
            std::cout << "No sensor with ID: " << id << std::endl;
        }
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unable to remove sensor with Id: " << id << " reason: " << e.what();
        return false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << std::endl;
        return false;
    }
}