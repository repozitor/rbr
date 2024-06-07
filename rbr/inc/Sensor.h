#pragma once
#include "pch.h"

namespace rbr {

    class Sensor {
    public:
        Sensor() = delete;
        Sensor(int id, int interval);
        virtual ~Sensor();

        void start();
        void stop();
        int getId() const;

        virtual std::string generateData() const = 0;

    protected:
        void run();
        std::string getTimeStamp() const;

        int m_id;
        int m_interval;
        std::mutex m_threadLock;
        std::atomic<bool> m_running;
        std::condition_variable conditionalSleep;
        std::thread m_thread;
        std::chrono::time_point<std::chrono::system_clock> m_timeNow;
    };

}