#include <iostream>
#include <list>
#include <map>
#include <string>
#include <fstream>
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
			cout << (it->second.size() == 1 ? "Нарушение (" : "Нарушений (") << it->second.size() << "):" << endl;
			for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
			{
				V->print();
			}
			cout << endl;
		}
	}
	void printByCarNumber(const std::string& Number)const
	{
		cout << "Данные по номеру" << endl;
		std::map<std::string, std::list<Violations>>::const_iterator it = database.find(Number);

		if (it == database.end())
		{
			cout << "Машина с этим номером не найдена" << endl;
			return;
		}

		cout << "Номер машины: " << it->first << endl;
		cout << "" << it->second.size() << endl;
		for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
		{
			V->print();
		}
	}
	void printByCarNumberRange(const std::string& Number_first, const std::string& Number_second) const
	{
		cout << "Данные по диапазону номеров" << endl;
		for (std::map<std::string, std::list<Violations>>::const_iterator it = database.begin(); it != database.end(); ++it)
		{
			if (it->first >= Number_first && it->first <= Number_second)
			{
				cout << endl << "Номер машины: " << it->first << endl;
				cout << "Количество нарушений: " << it->second.size() << endl;
				for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
				{
					V->print();
				}
				cout << endl;
			}
		}
	}
	void SaveToFile(const std::string& filename) const
	{
		std::ofstream fout;

		fout.open(filename, std::ios::app);

		if (!fout.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		for (std::map<std::string, std::list<Violations>>::const_iterator it = database.begin(); it != database.end(); ++it)
		{
			for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
			{
				fout << it->first << "|" << V->toString() << endl;
			}
		}
		fout.close();
		cout << "Данные успешно загружены: " << filename << endl;
	}
	void LoadFromFile(const std::string& filename)const
	{
		std::ifstream fin(filename);

		if (!fin.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
			return;
		}

		std::string line;
		/*while (std::getline(fin, line))
		{

		}*/
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	PoliceDataBase police;

	police.addViolations("А423НР", Violations("2024-01-15", "Превышение скорости", 500.0));
	police.addViolations("А423НР", Violations("2024-01-20", "Неправильная парковка", 300.0));
	police.addViolations("Т742МА", Violations("2024-01-18", "Проезд на красный свет", 5000.0));
	police.addViolations("М907ММ", Violations("2024-01-22", "Отсутствие страховки", 800.0));
	police.addViolations("В123АВ", Violations("2024-01-25", "Непристегнутый ремень", 1000.0));
	police.addViolations("С456СЕ", Violations("2024-01-30", "Превышение скорости", 500.0));

	cout << "\tТЕСТИРОВАНИЕ БАЗЫ ДАННЫХ ГАИ" << endl;

	police.printDataBase();

	police.printByCarNumber("А423НР");
	police.printByCarNumber("Х999ХХ");

	police.printByCarNumberRange("А100АА", "В200ВВ");
	police.printByCarNumberRange("Х100ХХ", "Х999ХХ");

}