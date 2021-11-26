#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

/**
* \brief Функция для получения квадрата числа.
* \param number Параметр степени числа.
* \return Квадрат числа.
*/
int SecondDegree(int number);

/**
* \brief Функция для получения обработанного массива.
* \param arr Параметр обработанного массива.
* \param sizeN Параметр количества столбов.
* \param sizeM Параметр количества строк.
* \return Обработанный массива.
*/
int** AddRows(int** arr, size_t sizeN, size_t sizeM);

/**
* \brief Функция для получения элементов массива.
* \param arr Параметр массива.
* \param sizeN Параметр количества столбов.
* \param sizeM Параметр количества строк.
* \return Обработанный массива.
*/
void InputUserArray(int** arr, size_t sizeN, size_t sizeM);

/**
* \brief Функция для получения случайных элементов массива.
* \param matrix Параметр массива со случайными элементами.
* \param min Параметр нижнего предела интервала.
* \param max Параметр верхнего предела интервала.
* \return Обработанный массива.
*/
void FillRandomArray(int** matrix, int sizeN, int sizeM, const int min, const int max);

/**
* \brief Функция для вывода полученного массива.
* \param arr Параметр массива.
* \param sizeN Параметр количества столбов.
* \param sizeM Параметр количества строк.
* \return Обработанный массива.
*/
void OutputArray(int** arr, size_t sizeN, size_t sizeM);

/**
* \brief Функция для подчистки памяти от массива.
* \param arr Параметр массива.
* \param new_arr Параметр второго массива.
* \param sizeN Параметр количества столбов.
* \param sizeM Параметр количества строк.
* \return Обработанный массива.
*/
void NegativeElement(int** arr, int** new_arr, size_t sizeN, size_t sizeM);

enum class Input
{
    /**
    * \brief Неправильно сформулированный выбор.
    */
    none,

    /**
    * \brief Заполнение массива случайными числами.
    */
    random_number,

    /**
    * \brief Заполнение массива пользователем.
    */
    user_number
};

/**
* \brief
* \param message
* \return
*/
Input ReadUserChoice(const string& message);


int main()
{
	const int n = 8; // количество элементов массива
	int m[n] = { -10 ; 20}; // переменная для хранения массива
	int sum = 0; // переменная для хранения суммы отрицательных элементов
	int m1[2]; // переменная для хранения индексов отрицательных эл. массива
	int j = 0;
	int sum2 = 0; // переменная для хранения суммы положительных элементов

	int cout << " исходный массив " << endl;

	// выводим значения исходного массива 
	for (int i = 0; i < n; i++)
		cout << "m[" << i << "] = " << m[i] << endl;

	// находим сумму отрицательных элементов массива
	for (int i = 0; i < n; i++)
		if (m[i] < 0)
			sum += m[i];
	int cout << " сумма отрицательных элементов = " << sum << endl;

	// находим индексы отрицательных элементов массива
	for (int i = 0; i < n; i++)
		if (m[i] < 0) {
			m1[j] = i;
			cout << "индекс " << j + 1 << " = " << m1[j] << endl;
			j = j + 1;
		}

	return (0);
}