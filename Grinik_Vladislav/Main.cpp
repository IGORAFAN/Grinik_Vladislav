#include"ClassTriangle.h"

int main() {
	setlocale(LC_ALL, "Russian"); // ��������� �����
	system("color 02"); // ��������� �����

	Triangle obj1; // �������� ������� ������ ������������
	obj1.what_u_want();  // ����� ������ � �������
	obj1.get_Result(); // ����� ������ � �������
	obj1.restart_program(); // ����� ������ � �������

	_getch(); //�������� �����
	return 0;
}