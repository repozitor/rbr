// RBR-TechChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include "SensorManager.h"
#include "Sensor.h"

std::mutex cout_mtx;

void printUsage() {
	std::cout << "Usage:\n->  for adding a sensor \t\"add\"\n" <<
		"->  for removing a sensor \t\"remove\"\n" <<
		"->  for listing sensors \t\"list\"\n" <<
		"Example: add [p|t|c] for adding pressure|temperature|conductivity\n\n";
	std::cout.flush();
}

void inputCommandProcessor(rbr::SensorManager& container)
{
	std::string line;
	std::cout << "\n>> ";

	while (std::getline(std::cin, line))
	{
		std::lock_guard<std::mutex> lock(cout_mtx);

		std::istringstream iss(line);
		std::string command;
		iss >> command;

		if (command == "add")
		{
			std::string type;
			iss >> type;

			container.addSensor(type);

		}
		else if (command == "list")
		{
			container.listSensors();
		}
		else if (command == "remove")
		{
			int id;
			iss >> id;
			container.removeSensor(id);
		}
		else if (command == "exit") 
		{
			return;
		}
		else if (command == "help")
		{
			printUsage();
		}
		else 
		{
			std::cout << "Error. invalid command! Try add|remove|list|exit|help";
		}
		std::cout << "\n>> ";
	}
}

int main()
{
	try {
		printUsage();

		rbr::SensorManager container;
		std::cout << "Sensor Manager Created\n";

		std::thread uiThread(inputCommandProcessor, std::ref(container));
		std::cout << "Sensor  Manager Started\n";

		uiThread.join();
		std::cout << "Shutting down Sensor  Manager\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch (...)
	{
		std::cerr << "Unknown error" << std::endl;
	}

	std::cout << "Shutting down app ...\n";
	return 0;
}
