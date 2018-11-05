#pragma once //Макрос который заставляет подключать файл один раз там где его вызывают

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>

using namespace std; //Пространство имен std

class Triangle //создание класса Треугольник
{
private: //Приватные данные
	double a, b, c; //Вводимые данные
	double perimeter = 0; //Периметр
	double halfPerim = 0; //Полу периметр
	double area = 0; //Площадь
	double height = 0; //Высота
	double alpha_Angle = 0; //Уголь альфа
	double beta_Angle = 0; //Уголь бета
	double gamma_Angle = 0; //Уголь гамма

	int indexTriangle = 0; //Флаг обозначающий тип треугольника
	int whatVariant = 0; //Номер выбора
	const double radianToGradus = 57.2958; //Равенство одной радианы
public:
	Triangle(); //Конструктор обьекта один
	~Triangle();//Деструктор обьекта один

	void prewiew(); //Приветствие 
	void set_Data(); //Установка данных
	void what_u_want(); //Установка выбора
	void find_perimeter(); //Поиск периметра
	void find_Area(); //Поиск площади
	void find_height(); //Поиск высоты
	void find_degrees(); //Поиск угла
	void what_Triangle(); //Вид треугольника
	void get_Result(); //Получение результатов
	void restart_program(); //Перезагрузка програмы
};