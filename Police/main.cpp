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
		cout << "����: " << Date << " ���������: " << Type << " ���������: " << Cost << " ���." << endl;
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
		cout << "\t\t���� ������" << endl;
		if (database.empty())
		{
			cout << "���� ������ �����" << endl;
			return;
		}
		for (std::map<std::string, std::list<Violations>>::const_iterator it = database.begin(); it != database.end(); ++it)
		{
			cout << "����� ������: " << it->first << endl;
			cout << "���������/� (" << it->second.size() << "):" << endl;
			cout << (it->second.size() == 1 ? "��������� (": "��������� (") << it->second.size() << "):" << endl;
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

	Police.addViolations("�423��", Violations("2024-01-15", "��������� ��������", 500.0));
	Police.addViolations("�423��", Violations("2024-01-20", "������������ ��������", 300.0));
	Police.addViolations("�742��", Violations("2024-01-18", "������ �� ������� ����", 5000.0));
	Police.addViolations("�907��", Violations("2024-01-22", "���������� ���������", 800.0));

	Police.printDataBase();
}