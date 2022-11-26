// Points.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Point3D.h"
#include "Point3Dh.h"
#include <conio.h> // для _getch
#include <vector>

class Points
{
	std::vector<Point3D> Points;
	std::vector<Point3Dh> Points3Dh;
public:
	void add_point();
	void print_points();
	void remove_point();
	//Points 3Dh
	void add_point_3Dh();
	void print_points_3Dh();
	void remove_point_3Dh();

};

int set_value()
{
	int value;
	while (!(std::cin >> value))
	{
		if (std::cin.eof())
		{
			throw "eof";
		}
		std::cin.clear(); //Сбрасываем флаг ошибки, если таковая была
		std::cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		std::cout << "Try again: ";
	}
	return value;
}

int set_value_double()
{
	double value;
	while (!(std::cin >> value))
	{
		if (std::cin.eof())
		{
			throw "eof";
		}
		std::cin.clear(); //Сбрасываем флаг ошибки, если таковая была
		std::cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		std::cout << "Try again: ";
	}
	return value;
}

Point3D create_point()
{
    int x, y, z;
	char letter;
	std::cout << "Enter Letter: ";
	std::cin >> letter;
	std::cout << "Enter X: ";
	x = set_value();
	std::cout << "Enter Y: ";
	y = set_value();
	std::cout << "Enter Z: ";
	z = set_value();
	Point3D *newpoint =  new Point3D(x, y, z, letter);
	return *newpoint;
}

Point3Dh create_point_3Dh()
{
	int x, y, z;
	double h;
	char letter;
	std::cout << "Enter Letter: ";
	std::cin >> letter;
	std::cout << "Enter X: ";
	x = set_value();
	std::cout << "Enter Y: ";
	y = set_value();
	std::cout << "Enter Z: ";
	z = set_value();
	std::cout << "Enter H: ";
	h = set_value_double();
	Point3Dh* newpoint = new Point3Dh(letter, x, y, z, h);
	return *newpoint;
}

void Points::add_point()
{
	Point3D newPoint = create_point();
	Points.push_back(newPoint);
}

void Points::print_points()
{
	if (Points.size() == 0)
	{
		std::cout << "List is empty!";
		_getch();
		return;
	}
	for (size_t i = 0; i < Points.size(); i++)
	{
		std::cout << i << ") ";
		Points[i].print_info();
	}
		_getch();
}

void Points::remove_point()
{
	std::cout << "Choose point which you want to remove: \n";
	for (size_t i = 0; i < Points.size(); i++)
	{
		std::cout << i << ") ";
		Points[i].print_info();
	}
	if (Points.size() == 0)
		return;
	int n = set_value();
	//system("cls");
	auto iter = Points.cbegin();
	Points.erase(iter + n);
}

void Points::add_point_3Dh()
{
	Point3Dh newPoint = create_point_3Dh();
	Points3Dh.push_back(newPoint);
}

void Points::print_points_3Dh()
{
	if (Points3Dh.size() == 0)
	{
		std::cout << "List is empty!";
		_getch();
		return;
	}
	for (size_t i = 0; i < Points3Dh.size(); i++)
	{
		std::cout << i << ") ";
		Points3Dh[i].print_info();
	}
	_getch();
}

void Points::remove_point_3Dh()
{
	std::cout << "Choose point which you want to remove: \n";
	for (size_t i = 0; i < Points3Dh.size(); i++)
	{
		std::cout << i << ") ";
		Points3Dh[i].print_info();
	}
	if (Points3Dh.size() == 0)
		return;
	int n = set_value();
	//system("cls");
	auto iter = Points3Dh.cbegin();
	Points3Dh.erase(iter + n);
}

int menu() {
	system("cls");
	std::cout <<
		"\n=====Points========\n\n"
		"1. Append point\n"
		"2. Print points list\n"
		"3. Remove point\n"
		"\n=====Points3Dh=====\n\n"
		"4. Append point\n"
		"5. Print points list\n"
		"6. Remove point\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};


int main()
{
	Points Points;
	while (true)
	{
		int cmd = menu();
		bool exit = false;
		switch (cmd) {
		case 0:
			exit = true;
			break;
		case 1:
			system("cls");
			Points.add_point();
			break;
		case 2:
			system("cls");
			Points.print_points();
			break;
		case 3:
			system("cls");
			Points.remove_point();
			break;
		case 4:
			system("cls");
			Points.add_point_3Dh();
			break;
		case 5:
			system("cls");
			Points.print_points_3Dh();
			break;
		case 6:
			system("cls");
			Points.remove_point_3Dh();
			break;
		};
		if (exit == true) break;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
