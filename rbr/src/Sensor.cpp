#include "pch.h"
#include "Sensor.h"

extern std::mutex cout_mtx;

using namespace rbr;

Sensor::Sensor(int id, int interval) :
	m_id(id),
	m_interval(interval),
	m_running(true),
	m_timeNow(std::chrono::system_clock::now())
{
	start();
}

Sensor::~Sensor()
{
	stop();
}

void Sensor::start()
{
	m_thread = std::thread(&Sensor::run, this);
}

void Sensor::stop()
{
	m_running = false;
	conditionalSleep.notify_one();

	if (m_thread.joinable()) {
		m_thread.join();
	}
}

int Sensor::getId() const
{
	return m_id;
}

void Sensor::run()
{
	std::unique_lock<std::mutex> lock(m_threadLock);

	while (m_running) {
		cout_mtx.lock();
		std::cout << "[" << getTimeStamp() << "]\tSensor id: " << m_id << "\tdata: " << generateData() << std::endl;
		cout_mtx.unlock();

		conditionalSleep.wait_for(lock, std::chrono::seconds(m_interval));
	}
}

std::string Sensor::getTimeStamp() const
{
	std::stringstream ss;
	struct tm time_info;

	std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	localtime_s(&time_info, &now_c);
	ss << std::put_time(&time_info, "%Y-%m-%d %H:%M:%S");

	return ss.str();
}
