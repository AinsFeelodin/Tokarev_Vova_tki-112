#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
* \brief Расчёт функции
* \param x Аргумент функции
* \return Значение функции
**/
double calcFunction(const double x);
/**
* \brief Проверка существования функции
* \param x Аргумент функции
* \return Проверка значения
**/
bool isCalculated(const double x);

int main()
{	
	setlocale(LC_ALL, "Russian");
	cout << fixed;
	const double LOWER_BOUND = 0.4, UPPER_BOUND = 1.0, STEP = 0.05;
	const size_t WIDTH = 5;

	cout << setw(WIDTH) << "X" << " | " << setw(2 * WIDTH) << "Y\n";

	for (double x = LOWER_BOUND; x < UPPER_BOUND + STEP; x += STEP)
	{
		if (isCalculated(x))
			cout << setw(WIDTH) << x << " | " << setw(2 * WIDTH) << "Невозможно вычислить значение в данной точке\n";
		else
			cout << setw(WIDTH) << x << " | " << setw(2 * WIDTH) << calcFunction(x) << "\n";
	}
	return 0;
}

double calcFunction(const double x)
{
	return x * sqrt(x) - sqrt(pow(x, 3)) - 2.5;
}

bool isCalculated(const double x)
{
	return (x <= 0);
}