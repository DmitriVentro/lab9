#include <iostream>
#include "cmath"
#include "Figure.hpp"
int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    Figure *F;
    do
    {
        std::cout << "Выбери тип фигуры:\n";
        std::cout << "1. Круг\n";
        std::cout << "1. Прямоугольник\n";
        std::cout << ">>>";
        std::cin >> choice;
        if (choice!=1 && choice !=2)
        {
            std::cout << "Ещё раз попробуй попасть по 1 или 2 кнопкам\n";
        }
    }
    while (choice !=1 && choice !=2);
    switch (choice)
    {
    case 1:
        F = new Circle(5);
        break;
    case 2:
        F = new Rectangle(5, 10);
        break;
    default:
        break;
    }
    F->show();
    cout << "\nОснование фигуры: " << F->calcArea() << std::endl;
    Cylinder *Cyl = new Cylinder(F, 10);
    Cyl->show();
    std::cout << "Объем цилиндра: " << Cyl->calcVolume() << std::endl;
    delete F;
    return 0;
}