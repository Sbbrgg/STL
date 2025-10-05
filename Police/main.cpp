#include <iostream>
#include <list>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::endl;

class Violations
{
	std::string Date;
	std::string Type;
	double Cost;
public:
	Violations(const std::string& date = "", const std::string& type = "", double cost = 0.0) : Date(date), Type(type), Cost(cost) {}

	void print()const
	{
		cout << "Дата: " << Date << " Нарушение: " << Type << " Стоимость: " << Cost << " руб." << endl;
	}
	std::string toString() const
	{
		return Date + "|" + Type + "|" + std::to_string(Cost);
	}
};

class PoliceDataBase
{
	std::map<std::string, std::list<Violations>> database;
public:
	void addViolations(const std::string& car_number, const Violations& violation)
	{
		database[car_number].push_back(violation);
	}
	void printDataBase() const
	{
		cout << "\t\tБаза данных" << endl;
		if (database.empty())
		{
			cout << "База данных пуста" << endl;
			return;
		}
		for (std::map<std::string, std::list<Violations>>::const_iterator it = database.begin(); it != database.end(); ++it)
		{
			cout << "Номер машины: " << it->first << endl;
			cout << "Нарушение/я (" << it->second.size() << "):" << endl;
			cout << (it->second.size() == 1 ? "Нарушение (": "Нарушений (") << it->second.size() << "):" << endl;
			for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
			{
				V->print();
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");

	PoliceDataBase Police;

	Police.addViolations("А423НР", Violations("2024-01-15", "Нарушение скорости", 500.0));
	Police.addViolations("А423НР", Violations("2024-01-20", "Неправильная парковка", 300.0));
	Police.addViolations("Т742МА", Violations("2024-01-18", "Проезд на красный свет", 5000.0));
	Police.addViolations("М907ММ", Violations("2024-01-22", "Отсутствие страховки", 800.0));

	Police.printDataBase();
}