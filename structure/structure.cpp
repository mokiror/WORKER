#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <WINDOWS.H>

struct Workerrr
{
	std::string lastname;
	double years;
	double moneyInHour;
	double hours;

	void AddInfo()
	{

		std::cout << "\n������� �������: ";
		std::cin >> lastname;
		std::cout << "������� ���� ������: ";
		std::cin >> years;
		std::cout << "������� �������� � ���: ";
		std::cin >> moneyInHour;
		std::cout << "������� ���� ������: ";
		std::cin >> hours;

	}

	void Info()
	{
		AddInfo();

		std::cout << "\n\n���������� � ���������: \n";
		std::cout << "���: " << lastname << std::endl;
		std::cout << "���� ������: " << years << std::endl;
		std::cout << "�������� � ���: " << moneyInHour << std::endl;
		std::cout << "���� ������: " << hours << std::endl;

	}

	void Count()
	{
		Info();

		std::ofstream information;
		information.open("information.txt");

		int counter = 0;
		int counter02 = 0;
		int anotherCounter = 0;
		double firstPrem = 0.05, secondPrem = 0.08, thirdPrem = 0.15;

		if (years <= 1)
		{
			std::cout << "������ - 0 % " << std::endl;
			counter02 = (years * 365 * moneyInHour * hours);
			std::cout << "������������ �����: " << counter02 << std::endl;
		}
		else if (1 < years && years < 3)
		{
			std::cout << "������ - 5 % " << std::endl;
			counter = (years * 365 * moneyInHour * hours);
			anotherCounter = (counter * firstPrem);
			counter02 = counter + anotherCounter;
			std::cout << "������������ �����: " << counter02 << std::endl;
		}
		else if (3 <= years && years < 5)
		{
			std::cout << "������ - 8 % " << std::endl;
			counter = (years * 365 * moneyInHour * hours);
			anotherCounter = (counter * secondPrem);
			counter02 = counter + anotherCounter;
			std::cout << "������������ �����: " <<  counter02 << std::endl;
		}
		else if (5 < years)
		{
			std::cout << "������ - 15 % " << std::endl;
			counter = (years * 365 * moneyInHour * hours);
			anotherCounter = (counter * thirdPrem);
			counter02 = counter + anotherCounter;
			std::cout << "������������ �����: " <<  counter02 << std::endl;
		}

		if (!information.is_open())
		{
			std::cerr << "Error\n";
		}
		else
		{
			information << "\n�������: " << lastname << "\n����: " << years << "\n�������� � ���: " <<
				moneyInHour << "\n���� ������: " << hours << "\n��������: " << counter02 << std::endl;
		}


		information.close();

	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Workerrr work01;
	work01.Count();


	return 0;
}
