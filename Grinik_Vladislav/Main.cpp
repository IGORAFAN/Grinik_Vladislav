#include"ClassTriangle.h"

int main() {
	setlocale(LC_ALL, "Russian"); // Установка языка
	system("color 02"); // Установка цвета

	Triangle obj1; // Создание обьекта класса треугольника
	obj1.what_u_want();  // вызов метода к обьекту
	obj1.get_Result(); // вызов метода к обьекту
	obj1.restart_program(); // вызов метода к обьекту

	_getch(); //Ожидание ввода
	return 0;
}