#include <iostream>

int i = 5; //global i

int main1()
{
	int j = 7;
	std::cout << "printing global var i:" << i << "\n";
	{
		int i = 10, j = 11;
		std::cout << "printing local var i:" << i << "\n";
		std::cout << "printing global var i:" << ::i << "\n"; // note the :: scope resolution
		std::cout << "printing local var j:" << j << "\n"; // note the :: scope resolution
		std::cout << "note that j=7 is inaccessible here" << "\n";
	}
	std::cout << "printing var j:" << j << "\n";

	return 0;

}