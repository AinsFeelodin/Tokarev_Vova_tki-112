#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <iostream>

double GetA(const double x);
/**
* \brief Функция для расчёта a
* \param x Параметр x
* \return Возвращает значение переменной GetA
*/
double GetB(const double x, const double y);
/**
* \brief Функция для расчёта b
* \param x Параметр x
* \param y Параметр y
* \return Возвращает значение переменной GetB
*/

/**
* \brief Точка входа в программу
* \return Возращает нуль, в случае успеха
*/

int main()
{
	const double x = 0.335;
	const double y = 0.025;

	const auto a = GetA(x);
	const auto b = GetB(x, y);

	std::cout << "x =" << x << ", y =" << y << "\n";
	std::cout << "a =" << a << ", b =" << b << std::endl;

	return 0;

}

double GetA(const double x)
{
	return 1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4);
}

double GetB(const double x, const double y)
{
	return x * (sin(pow(x, 3)) + cos(pow(y, 2)));
}