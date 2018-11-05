#pragma once //������ ������� ���������� ���������� ���� ���� ��� ��� ��� ��� ��������

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>

using namespace std; //������������ ���� std

class Triangle //�������� ������ �����������
{
private: //��������� ������
	double a, b, c; //�������� ������
	double perimeter = 0; //��������
	double halfPerim = 0; //���� ��������
	double area = 0; //�������
	double height = 0; //������
	double alpha_Angle = 0; //����� �����
	double beta_Angle = 0; //����� ����
	double gamma_Angle = 0; //����� �����

	int indexTriangle = 0; //���� ������������ ��� ������������
	int whatVariant = 0; //����� ������
	const double radianToGradus = 57.2958; //��������� ����� �������
public:
	Triangle(); //����������� ������� ����
	~Triangle();//���������� ������� ����

	void prewiew(); //����������� 
	void set_Data(); //��������� ������
	void what_u_want(); //��������� ������
	void find_perimeter(); //����� ���������
	void find_Area(); //����� �������
	void find_height(); //����� ������
	void find_degrees(); //����� ����
	void what_Triangle(); //��� ������������
	void get_Result(); //��������� �����������
	void restart_program(); //������������ ��������
};