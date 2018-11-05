#include "ClassTriangle.h" //����������� ����� ������

Triangle::Triangle() : a(0), b(0), c(0) { //��������� ��������� �������
	prewiew();
	set_Data();
}
Triangle::~Triangle() {} //���������� ������� ����

void Triangle::prewiew() {
	cout << "������" << endl;
	cout << "��������� ������� ��� �������� ������������";
}
void Triangle::set_Data() {
	for (;;) {
		cout << "\n������� ������� a>";
		cin >> a; //���� ������
		if (!cin) {
			cout << "�� ��������� ������� ������\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	for (;;) {
		cout << "������� ������� b>";
		cin >> b; //���� ������
		if (!cin) {
			cout << "�� ��������� ������� ������\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	for (;;) {
		cout << "������� ������� c>";
		cin >> c; //���� ������
		if (!cin) {
			cout << "�� ��������� ������� ������\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	if (a >= (b + c) || b >= (a + c) || c >= (b + a)) {
		cout << "������ ������������ �� ����������!";
		_getch();
		system("cls");
		cout << "��������� ����!";
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
	cout << "\n�������� �������� � �������������: ";    //����� ��������
	cout << "\n1 - ����� ��������� ������������";    //����� ��������
	cout << "\n2 - ����� ������� ������������";    //����� ��������
	cout << "\n3 - ����� ������ ������������";    //����� ��������
	cout << "\n4 - ����� ����� ������������";    //����� ��������
	cout << "\n5 - ����� ���� ������������";    //����� ��������
	cout << "\n6 - ������� ��� ���������� �� �����!";    //����� ��������
	cout << "\n0 - ����� ������� ������";    //����� ��������
	cout << "\n����>";
	cin >> whatVariant; //���� ��������� ������ � ����

	if (whatVariant < 0 || whatVariant > variant) {   //�������� �����
		cout << "����������� �������� ������! ��������� ����:\n";
		_getch();
		system("cls"); //������� ������ ������
		what_u_want(); //�������� �������
	}
	else {   // �����
		switch (whatVariant) {
		case 1:  //�������� �������� �� ����
			find_perimeter();
			break;
		case 2:  //�������� �������� �� ����
			find_perimeter();
			find_Area();
			break;
		case 3:  //�������� �������� �� ����
			find_perimeter();
			find_height();
			break;
		case 4:  //�������� �������� �� ����
			find_perimeter();
			find_height();
			find_Area();
			find_degrees();
			break;
		case 5: //�������� �������� �� ���� 
			find_perimeter();
			find_height();
			find_Area();
			find_degrees();
			what_Triangle();
			break;
		case 6: //�������� �������� �� ���� 
			find_perimeter();
			find_height();
			find_Area();
			find_degrees();
			what_Triangle();
			break;
		case 0:  //����� ������???
			set_Data();
			what_u_want();
			break;
		default:
			break;
		}
	}
}
void Triangle::find_perimeter() { //��������
	perimeter = a + b + c; //������� ������ ���������
	halfPerim = ((a + b + c) / 2); //������� ������ ���� ���������
}
void Triangle::find_Area() { //�����
	area = sqrt(halfPerim * (halfPerim - a) * (halfPerim - b) * (halfPerim - c)); //������� ������ �������
}
void Triangle::find_height() { //������
	height = 2 * (sqrt(halfPerim * (halfPerim - a) * (halfPerim - b) * (halfPerim - c)) / a); //������� ������ ������
}
void Triangle::find_degrees() { //������� ������ ����
	alpha_Angle = acos((pow(c, 2) + pow(b, 2) - pow(a, 2)) / ((2 * b * c))) * radianToGradus; //������� ������ ���� �����
	beta_Angle	= acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / ((2 * a * c))) * radianToGradus; //������� ������ ���� ����
	gamma_Angle = acos((pow(b, 2) + pow(a, 2) - pow(c, 2)) / ((2 * a * b))) * radianToGradus; //������� ������ ���� �����

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

void Triangle::get_Result() {  //������� ������ �����������
	cout << endl << endl << "�����: ---------------------------------------------------------" << endl;
	switch (whatVariant) {
	case 1:
		cout << "�������� ��e���������: " << perimeter; //������������ ����� ��� ������ ���������
		break;
	case 2:
		cout << "\n������� ��e���������: " << area; //������������ ����� ��� ������ �������
		break;
	case 3:
		cout << "\n������ ��e���������: " << height; //������������ ����� ��� ������ ������
		break;
	case 4:
		cout << "\n���� Alpha: " << alpha_Angle << "\n���� Beta: " << beta_Angle << "\n���� Gamma: " << gamma_Angle; //������������ ����� ��� ������ �����
		break;
	case 5:
		switch (indexTriangle) {  //????
		case 1:
			cout << "\n����������� �������� - �������������� ";
			break;
		case 2:
			cout << "\n����������� �������� - �������������� ";
			break;
		case 3:
			cout << "\n����������� �������� - �������������";
			break;
		case 0:
			cout << "\n����������� �� ����� ������������ ����\n";
			break;
		default:
			break;
		}break;
	case 6:  //��� ���������� ������� ����������
		cout << "\n�������� ��e���������: " << perimeter;
		cout << "\n������� ��e���������: " << area;
		cout << "\n������ ��e���������: " << height;
		cout << "\n���� Alpha: " << alpha_Angle << "\n����  Beta: " << beta_Angle << "\n���� Gamma: " << gamma_Angle;
		switch (indexTriangle) {
		case 1:
			cout << "\n����������� �������� - �������������� ";
			break;
		case 2:
			cout << "\n����������� �������� - �������������� ";
			break;
		case 3:
			cout << "\n����������� �������� - �������������";
			break;
		case 0:
			cout << "\n����������� �� ����� ������������ ����\n";
			break;
		}break;
	}
}

void Triangle::restart_program() {  //����������� ���������
	cout << endl << endl << "������������� ���������?" << endl;
	cout << "1 - ����������" << endl;  //������������ ���������
	cout << "0 - �������� ���������" << endl; // ��������
	int temp; //��������� ���������� ???
	cout << "����>";
	cin >> temp; //����� ��������
	if (temp < 0 || temp > 1) { //������ ���������� �����
		cout << "����������� �������� �����! ��������� ����!\n";
		cout << "����>";
		cin >> temp; //������ ����� ��������
	}
	if (temp < 0 || temp > 1) { //������������ ���� ��� ����
		cout << "����������� �������� �����! �������� ���������!";
		_getch();
		exit(0);  //�������� ���������
	}
	else if (temp == 1) { //������������ ���������
		system("cls");  //������� ���������
		set_Data(); //��������� ������
		what_u_want(); //��������� ������
		get_Result(); //��������� �����������
		restart_program(); //������������ ��������
	}
	else exit(0); //
}