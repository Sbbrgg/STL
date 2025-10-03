#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------------------------------------------------------------\n"
#define ВЫВОД_ВЕКТОРА for (int i : vec)cout << i << tab; cout << endl;
#define ВЫВОД_ЛИСТА for (int i : list)cout << i << tab; cout << endl;
#define ВЫВОД_Ф_ЛИСТА for (int i : flist)cout << i << tab; cout << endl;

template<typename T>void vector_info(const std::vector<T>& vec);
template<typename T>void deque_info(const std::deque<T>& vec);

//#define STL_ARRAY
#define STL_VECTOR
#define STL_DEQUE
//#define STL_HOMEWORK
//#define 

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	throw;
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2; i++)
		{
			cout << arr.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	/*catch (...)
	{
		std::cout << "Error: Something went wrong" << endl;
	}*/
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);

	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);
	//vec.shrink_to_fit();
	vec.reserve(14);
	vec.push_back(1024);
	vector_info(vec);

	/*vec.resize(18);*/
	for (int i : vec)cout << i << tab;cout << endl;
	vector_info(vec);
	cout << vec.front() << endl;
	cout << vec.back();
	cout << endl;
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	vec.insert(vec.begin()+index, value);
	for (int i : vec)cout << i << tab; cout << endl;

#endif // STL_VECTOR

#ifdef STL_HOMEWORK
	//				VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	ВЫВОД_ВЕКТОРА
	int index;
	cout << "Введите индекс удаляемого числа: "; cin >> index;
	vec.erase(vec.cbegin() + index);
	ВЫВОД_ВЕКТОРА
	//

	//				LIST
	std::list<int> list = { 0,1,1,2,3,5,8,13,21,34 };
	int value;
	cout << "Введите индекс добавляемого числа: "; cin >> index;
	cout << "Введите значение добавляемого числа: "; cin >> value;
	ВЫВОД_ЛИСТА

	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < index; i++)
		++it;
	list.insert(it, value);

	ВЫВОД_ЛИСТА
	cout << "Введите индекс удаляемого числа: "; cin >> index;
	it = list.begin();
	for (int i = 0; i < index; i++)
		++it;
	list.erase(it);
	ВЫВОД_ЛИСТА

	//					FORWARD_LIST
	std::forward_list<int> flist = { 0,1,1,2,3,5,8,13,21,34 };
	ВЫВОД_Ф_ЛИСТА
	cout << "Введите индекс добавляемого числа: "; cin >> index;
	cout << "Введите значение добавляемого числа: "; cin >> value;
	ВЫВОД_Ф_ЛИСТА

	std::forward_list<int>::iterator flist_it = flist.before_begin();
	for (int i = 0; i < index; i++) ++flist_it;
	flist.insert_after(flist_it, value);
	ВЫВОД_Ф_ЛИСТА

	flist_it = flist.before_begin();
	cout << "Введите индекс удаляемого числа: "; cin >> index;
	for (int i = 0; i < index; i++)++flist_it;
	flist.erase_after(flist_it);
	ВЫВОД_Ф_ЛИСТА



#endif // STL_HOMEWORK

#ifdef STL_DEQUE
	std::deque<int> deque = {3,5,8,13,21};
	deque.push_front(34);
	deque.push_back(2);

	deque_info(deque);
	deque.assign(vec.begin() + 3, vec.end() - 3);
	for (int i : deque)cout << i << tab; cout << endl;
#endif // STL_DEQUE


}

template<typename T>void vector_info(const std::vector<T>& vec)
{
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << delimiter << endl;
}
template<typename T>void deque_info(const std::deque<T>& vec)
{
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << delimiter << endl;
}