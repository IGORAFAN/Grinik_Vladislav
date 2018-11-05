#include "ClassTriangle.h" //Подключение файла класса

Triangle::Triangle() : a(0), b(0), c(0) { //Обнуление атрибутов обьекта
	prewiew();
	set_Data();
}
Triangle::~Triangle() {} //Деструктор обьекта один

void Triangle::prewiew() {
	cout << "Привет" << endl;
	cout << "Программа создана для просчёта Треугольника";
}
void Triangle::set_Data() {
	for (;;) {
		cout << "\nВведите сторону a>";
		cin >> a; //Ввод данных
		if (!cin) {
			cout << "Не корректно введены данные\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	for (;;) {
		cout << "Введите сторону b>";
		cin >> b; //Ввод данных
		if (!cin) {
			cout << "Не корректно введены данные\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	for (;;) {
		cout << "Введите сторону c>";
		cin >> c; //Ввод данных
		if (!cin) {
			cout << "Не корректно введены данные\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	if (a >= (b + c) || b >= (a + c) || c >= (b + a)) {
		cout << "Такого треугольника не существует!";
		_getch();
		system("cls");
		cout << "Повторите ввод!";
		set_Data();
	}
}

//while (true)
//{
//	cout << "Vvedite chislo: ";
//	cin >> n;
//	if (!cin)
//	{
//		cout << "ne verno vveli, povtorite vvod\n";
//		cin.clear();
//		while (cin.get() != '\n');
//	}
//	else break;
//}

void Triangle::what_u_want() {
	const int variant = 6;
	cout << "\nВыберите операцию с треугольником: ";    //Выбор операции
	cout << "\n1 - Поиск периметра треугольника";    //Выбор операции
	cout << "\n2 - Поиск площади треугольника";    //Выбор операции
	cout << "\n3 - Поиск высоты треугольника";    //Выбор операции
	cout << "\n4 - Поиск углов треугольника";    //Выбор операции
	cout << "\n5 - Поиск вида треугольника";    //Выбор операции
	cout << "\n6 - Вывести всю информацию на экран!";    //Выбор операции
	cout << "\n0 - Сброс введёных данных";    //Выбор операции
	cout << "\nВвод>";
	cin >> whatVariant; //Ввод выбраного номера в меню

	if (whatVariant < 0 || whatVariant > variant) {   //Проверка ввода
		cout << "Неправильно Введенны данные! Повторите Ввод:\n";
		_getch();
		system("cls"); //Очистка экрана вывода
		what_u_want(); //Рекурсия функции
	}
	else {   // Иначе
		switch (whatVariant) {
		case 1:  //Варианты действый из меню
			find_perimeter();
			break;
		case 2:  //Варианты действый из меню
			find_perimeter();
			find_Area();
			break;
		case 3:  //Варианты действый из меню
			find_perimeter();
			find_height();
			break;
		case 4:  //Варианты действый из меню
			find_perimeter();
			find_height();
			find_Area();
			find_degrees();
			break;
		case 5: //Варианты действый из меню 
			find_perimeter();
			find_height();
			find_Area();
			find_degrees();
			what_Triangle();
			break;
		case 6: //Варианты действый из меню 
			find_perimeter();
			find_height();
			find_Area();
			find_degrees();
			what_Triangle();
			break;
		case 0:  //Сброс данных???
			set_Data();
			what_u_want();
			break;
		default:
			break;
		}
	}
}
void Triangle::find_perimeter() { //Периметр
	perimeter = a + b + c; //Формула поиска периметра
	halfPerim = ((a + b + c) / 2); //Формула поиска полу периметра
}
void Triangle::find_Area() { //Площа
	area = sqrt(halfPerim * (halfPerim - a) * (halfPerim - b) * (halfPerim - c)); //Формула поиска площади
}
void Triangle::find_height() { //Высота
	height = 2 * (sqrt(halfPerim * (halfPerim - a) * (halfPerim - b) * (halfPerim - c)) / a); //Формула поиска высоты
}
void Triangle::find_degrees() { //Формула поиска угла
	alpha_Angle = acos((pow(c, 2) + pow(b, 2) - pow(a, 2)) / ((2 * b * c))) * radianToGradus; //Формула поиска угла альфа
	beta_Angle	= acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / ((2 * a * c))) * radianToGradus; //Формула поиска угла бета
	gamma_Angle = acos((pow(b, 2) + pow(a, 2) - pow(c, 2)) / ((2 * a * b))) * radianToGradus; //Формула поиска угла гамма

}
void Triangle::what_Triangle() { //???
		 if ((a == b) && (b==c))         indexTriangle = 1;
	else if (alpha_Angle == beta_Angle)  indexTriangle = 2;
	else if (beta_Angle == gamma_Angle)	 indexTriangle = 2;
	else if (alpha_Angle == gamma_Angle) indexTriangle = 2;
	else if ((89.9 <= alpha_Angle) && (alpha_Angle <= 90.1)) indexTriangle = 3;
	else if ((89.9 <= beta_Angle) && (beta_Angle <= 90.1))	 indexTriangle = 3;
	else if ((89.9 <= gamma_Angle) && (gamma_Angle <= 90.1)) indexTriangle = 3;
	else indexTriangle = 0;
}

void Triangle::get_Result() {  //Функция вывода результатов
	cout << endl << endl << "Ответ: ---------------------------------------------------------" << endl;
	switch (whatVariant) {
	case 1:
		cout << "Периметр Трeугольника: " << perimeter; //Получившийся ответ при поиске периметра
		break;
	case 2:
		cout << "\nПлощадь Трeугольника: " << area; //Получившийся ответ при поиске площади
		break;
	case 3:
		cout << "\nВысота Трeугольника: " << height; //Получившийся ответ при поиске высоты
		break;
	case 4:
		cout << "\nУгол Alpha: " << alpha_Angle << "\nУгол Beta: " << beta_Angle << "\nУгол Gamma: " << gamma_Angle; //Получившийся ответ при поиске углов
		break;
	case 5:
		switch (indexTriangle) {  //????
		case 1:
			cout << "\nТреугольник является - Равносторонним ";
			break;
		case 2:
			cout << "\nТреугольник является - Равнобедренным ";
			break;
		case 3:
			cout << "\nТреугольник является - Прямоугольным";
			break;
		case 0:
			cout << "\nТреугольник не имеет определённого вида\n";
			break;
		default:
			break;
		}break;
	case 6:  //Все результаты которые получились
		cout << "\nПериметр Трeугольника: " << perimeter;
		cout << "\nПлощадь Трeугольника: " << area;
		cout << "\nВысота Трeугольника: " << height;
		cout << "\nУгол Alpha: " << alpha_Angle << "\nУгол  Beta: " << beta_Angle << "\nУгол Gamma: " << gamma_Angle;
		switch (indexTriangle) {
		case 1:
			cout << "\nТреугольник является - Равносторонним ";
			break;
		case 2:
			cout << "\nТреугольник является - Равнобедренным ";
			break;
		case 3:
			cout << "\nТреугольник является - Прямоугольным";
			break;
		case 0:
			cout << "\nТреугольник не имеет определённого вида\n";
			break;
		}break;
	}
}

void Triangle::restart_program() {  //Перезапуска программы
	cout << endl << endl << "Перезапустить программу?" << endl;
	cout << "1 - Перезапуск" << endl;  //Перезагрузка программы
	cout << "0 - Закрытие программы" << endl; // Закрытие
	int temp; //Временная переменная ???
	cout << "Ввод>";
	cin >> temp; //Выбор действия
	if (temp < 0 || temp > 1) { //Провер введенного числа
		cout << "Неправильно Введенно число! Повторите Ввод!\n";
		cout << "Ввод>";
		cin >> temp; //Второй выбор действия
	}
	if (temp < 0 || temp > 1) { //Неправильный ввод два раза
		cout << "Неправильно Введенно число! Закрытие программы!";
		_getch();
		exit(0);  //Закрытие программы
	}
	else if (temp == 1) { //Перезагрузка программы
		system("cls");  //Очистка программы
		set_Data(); //Установка данных
		what_u_want(); //Установка выбора
		get_Result(); //Получение результатов
		restart_program(); //Перезагрузка програмы
	}
	else exit(0); //
}