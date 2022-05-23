/*
 * Main Test
 */
#include <iostream>
#include "List.cpp"

void list_test() 
{
	List<int> list = List<int>();

	for (int i = 0; i < 10; i++)
	{
		list.insert(0, i);
	}

	for (int i = 0; i < 3; i++)
	{
		list.erase(5);
	}

	list.at(2) = 10;

	for (int i = 0; i < list.size(); i++) 
	{
		std::cout << list.at(i) << " ";
	}
}

int main()
{
	list_test();
}