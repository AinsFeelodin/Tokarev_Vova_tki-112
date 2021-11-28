#define _USE_MATH_DEFINES 

#include <cmath>
#include <iostream>
#include <string>

using namespace std;



/*
*\brief Функция для расчета площади круга.
* \param radius Параметр - радиус.
* \return Площадь круга.
*/
double getSquareCircle(const int radius);

/*
*\brief Функция для расчета площади трапеции.
* \param a Параметр основания a.
* \param b Параметр основания b.
* \param h Параметр высоты h.
* \return Площадь трапеции.
*/
int getSquareTrapezoid(const int a, const int b, const int h);

/**
* \brief Ввод значений параметров.
* \param message Разъясняющая надпись.
* \return Значение параметра.
*/

enum class Figure
{
    Circle,
    Trapezoid
};

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Выберите с какой фигурой хотите работать:\n"
        << "Введите " << static_cast<int>(Figure::Circle) << " - для работы с кругом\n"
        << "Введите " << static_cast<int>(Figure::Trapezoid) << " - для работы с трапецией\nВаш выбор:";
    int choice;
    cin >> choice;
    const auto chosen = static_cast<Figure>(choice);

    switch (chosen) {
    case  Figure::Circle:
    {
        cout << "Введите радиус круга: ";
        int radius;
        cin >> radius;
        cout << "Площадь круга равна: " << getSquareCircle(radius);
        break;
    }
    case  Figure::Trapezoid:
    {
        cout << "Введите длину вверхней грани трапеции: ";
        int a;
        cin >> a;
        cout << "\nВведите длину нижней грани трапеции : ";
        int b;
        cin >> b;
        cout << "\nВведите высоту трапеции: ";
        int h;
        cin >> h;
        cout << "\nПлощадь трапеции равна: " << getSquareTrapezoid(a, b, h);
        break;
    }
    default:
    {
        cout << "Некоректный ввод.";
    }
    }
    return 0;
}

double getSquareCircle(const int radius)
{
    return 3.14 * pow(radius, 2);
}


int getSquareTrapezoid(const int a, const int b, const int h)
{
    return ((a + b) / 2) * h;
}