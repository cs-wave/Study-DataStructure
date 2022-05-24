/*
 * Main Test
 */
#include <iostream>
#include "List.cpp"

void list_test() 
{
	_List<int> list = _List<int>();

	for (int i = 0; i < 10; i++)
	{
		list._insert(0, i);
	}

	for (int i = 0; i < 3; i++)
	{
		list._erase(5);
	}

	list._at(2) = 10;

	for (int i = 0; i < list._size(); i++) 
	{
		std::cout << list._at(i) << " ";
	}
}

int main()
{
	list_test();
}