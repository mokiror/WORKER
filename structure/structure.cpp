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

		std::cout << "\nВведите фамилию: ";
		std::cin >> lastname;
		std::cout << "Введите стаж работы: ";
		std::cin >> years;
		std::cout << "Введите зарплату в час: ";
		std::cin >> moneyInHour;
		std::cout << "Введите часы работы: ";
		std::cin >> hours;

	}

	void Info()
	{
		AddInfo();

		std::cout << "\n\nИнформация о работнике: \n";
		std::cout << "Имя: " << lastname << std::endl;
		std::cout << "Стаж работы: " << years << std::endl;
		std::cout << "Зарплата в час: " << moneyInHour << std::endl;
		std::cout << "Часы работы: " << hours << std::endl;

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
			std::cout << "Премия - 0 % " << std::endl;
			counter02 = (years * 365 * moneyInHour * hours);
			std::cout << "Заработанная сумма: " << counter02 << std::endl;
		}
		else if (1 < years && years < 3)
		{
			std::cout << "Премия - 5 % " << std::endl;
			counter = (years * 365 * moneyInHour * hours);
			anotherCounter = (counter * firstPrem);
			counter02 = counter + anotherCounter;
			std::cout << "Заработанная сумма: " << counter02 << std::endl;
		}
		else if (3 <= years && years < 5)
		{
			std::cout << "Премия - 8 % " << std::endl;
			counter = (years * 365 * moneyInHour * hours);
			anotherCounter = (counter * secondPrem);
			counter02 = counter + anotherCounter;
			std::cout << "Заработанная сумма: " <<  counter02 << std::endl;
		}
		else if (5 < years)
		{
			std::cout << "Премия - 15 % " << std::endl;
			counter = (years * 365 * moneyInHour * hours);
			anotherCounter = (counter * thirdPrem);
			counter02 = counter + anotherCounter;
			std::cout << "Заработанная сумма: " <<  counter02 << std::endl;
		}

		if (!information.is_open())
		{
			std::cerr << "Error\n";
		}
		else
		{
			information << "\nФамилия: " << lastname << "\nСтаж: " << years << "\nЗарплата в час: " <<
				moneyInHour << "\nЧасы работы: " << hours << "\nЗарплата: " << counter02 << std::endl;
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
