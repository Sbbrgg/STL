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
			cout << (it->second.size() == 1 ? "��������� (" : "��������� (") << it->second.size() << "):" << endl;
			for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
			{
				V->print();
			}
			cout << endl;
		}
	}
	void printByCarNumber(const std::string& Number)const
	{
		cout << "������ �� ������" << endl;
		std::map<std::string, std::list<Violations>>::const_iterator it = database.find(Number);

		if (it == database.end())
		{
			cout << "������ � ���� ������� �� �������" << endl;
			return;
		}

		cout << "����� ������: " << it->first << endl;
		cout << "" << it->second.size() << endl;
		for (std::list<Violations>::const_iterator V = it->second.begin(); V != it->second.end(); ++V)
		{
			V->print();
		}
	}
	void printByCarNumberRange(const std::string& Number_first, const std::string& Number_second) const
	{
		cout << "������ �� ��������� �������" << endl;
		for (std::map<std::string, std::list<Violations>>::const_iterator it = database.begin(); it != database.end(); ++it)
		{
			if (it->first >= Number_first && it->first <= Number_second)
			{
				cout << endl << "����� ������: " << it->first << endl;
				cout << "���������� ���������: " << it->second.size() << endl;
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
			cout << "������ �������� �����!" << endl;
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
		cout << "������ ������� ���������: " << filename << endl;
	}
	void LoadFromFile(const std::string& filename)const
	{
		std::ifstream fin(filename);

		if (!fin.is_open())
		{
			cout << "������ �������� �����" << endl;
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

	police.addViolations("�423��", Violations("2024-01-15", "���������� ��������", 500.0));
	police.addViolations("�423��", Violations("2024-01-20", "������������ ��������", 300.0));
	police.addViolations("�742��", Violations("2024-01-18", "������ �� ������� ����", 5000.0));
	police.addViolations("�907��", Violations("2024-01-22", "���������� ���������", 800.0));
	police.addViolations("�123��", Violations("2024-01-25", "�������������� ������", 1000.0));
	police.addViolations("�456��", Violations("2024-01-30", "���������� ��������", 500.0));

	cout << "\t������������ ���� ������ ���" << endl;

	police.printDataBase();

	police.printByCarNumber("�423��");
	police.printByCarNumber("�999��");

	police.printByCarNumberRange("�100��", "�200��");
	police.printByCarNumberRange("�100��", "�999��");

}