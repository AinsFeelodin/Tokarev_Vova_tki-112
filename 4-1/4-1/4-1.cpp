#include <iostream>
#include <random>

using namespace std;

/*
* \brief заполнение массива случайными числами
* \param array массив
* \param size длина массива
*/
void randomDigits(int* array, const size_t size);

/*
* \brief ввод массива с клавиатуры
* \param array массив
* \param size длина массива
*/
void userInput(int* array, const size_t size);

/*
* \brief вывод массива на экран
* \param array массив
* \param size длина массива
* \param message сообщение, выводимое перед выводом массива
*/
void output(int* array, const size_t size, const string& message);

/*
* \brief нахождение суммы элементов с нечетными индексами
* \param array массив
* \param size длина массива
* \return сумма элементов
*/
int getOddIndexSum(int* array, const size_t size);


/*
* \brief нахождение количества элементов больших заданного числа и кратных пяти
* \param array массив
* \param size длина массива
* \param finder заданное число необходимое для поиска
* \return количество элементов удовлетворяющих условию
*/
int getNumberOfElementsIsGreaterThanFinderAndMultiplesOf5(int* array, const size_t size, const int finder);


/*
* \brief деление массива на первый элемент, если он отличен от нуля
* \param array массив
* \param size длина массива
*/
void divideAllElementstAnArrayByTheFirstElement(int* array, const size_t size);

/**
* \brief Выбор заполнеия массива
**/
enum class Input
{
	user_number = 1,
	random_number = 2
};

/*
* \brief Точка входа в программу
* \return Код ошибки(0 - успех)
*/
int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество эллементов массива: ";
	size_t size;
	cin >> size;

	int* myArray = new int[size];

	cout << "Как хотите заполнить массив?\nВведите: \n1 - для ввода массива с клавиатуры.\n2 - для заполнения массива случайными числами\n";
	int choice;
	cin >> choice;
	const auto chosen = static_cast<Input>(choice);
	switch (chosen) {
	case Input::random_number:
	{
		randomDigits(myArray, size);
		break;
	}
	case Input::user_number:
	{
		userInput(myArray, size);
		break;
	}
	default:
	{
		cout << "Некоректный ввод.";
		return 0;
	}
	}
	output(myArray, size, "Ваш массив:");

	cout << "\nСумма элементов массива имеющих нечетный индекс равна: " << getOddIndexSum(myArray, size) << "\n";

	cout << "Введите число, значение которого будет границей поиска количества элементов массива больших введенного числа и кратных пяти:";
	int finder;
	cin >> finder;
	cout << "Количество элементов массива больших " << finder << " и кратных пяти равно: " << getNumberOfElementsIsGreaterThanFinderAndMultiplesOf5(myArray, size, finder) << "\n";
	cout << "Производится деление элементов массива на первый элемент, подождите...\n";
	divideAllElementstAnArrayByTheFirstElement(myArray, size);
	output(myArray, size, "Ваш массив: ");

	delete[] myArray;
}

void randomDigits(int* array, const size_t size)
{
	const int min = -10;
	const int max = 20;

	std::random_device rd;
	std::mt19937 gen(rd());

	const std::uniform_int_distribution<> uniformIntDistribution(min, max);

	for (size_t index = 0; index < size; index++)
		array[index] = uniformIntDistribution(gen);
}

void userInput(int* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> array[i];
	}
}

void output(int* array, const size_t size, const string& message)
{
	cout << message << "[  ";
	for (size_t i = 0; i < size; i++)
		cout << array[i] << "  ";
	cout << "]";
}

int getOddIndexSum(int* array, const size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
		if (i % 2 != 0)
			sum += array[i];
	return sum;
}

int getNumberOfElementsIsGreaterThanFinderAndMultiplesOf5(int* array, const size_t size, const int finder)
{
	int number = 0;
	for (size_t i = 0; i < size; i++)
		if (array[i] > finder && array[i] % 5 == 0)
			number++;
	return number;
}

void divideAllElementstAnArrayByTheFirstElement(int* array, const size_t size)
{
	int buff = array[0];
	if (buff == 0)
		cout << "Невозможно провести деление. Первый элемент равен нулю\n";
	else
		for (size_t i = 0; i < size; i++)
			array[i] /= buff;
}