#include <iostream>
#include <climits>
using namespace std;

unsigned long long Factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
	
	try
	{
		cout << Factorial(5) << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}

unsigned long long Factorial(int n)
{
	if (n < 0)throw std::invalid_argument("������: ������������� �����");
	if (n == 0 || n == 1) return 1;
	if (n > 20)throw std::overflow_error("������: ������������");

	;
	return n * Factorial(n - 1);

}