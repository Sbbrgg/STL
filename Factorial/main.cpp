#include <iostream>
#include <climits>
using namespace std;

unsigned long long Factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
	
	try
	{
		cout << Factorial(-2) << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}

unsigned long long Factorial(int n)
{
	if (n < 0)throw std::invalid_argument("Ошибка: отрицательное число");
	if (n == 0 || n == 1) return 1;
	if (n > 20)throw std::overflow_error("Ошибка: переполнение");

	unsigned long long previous = Factorial(n - 1);
	return n * previous;

}