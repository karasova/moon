#include <iostream>
#include "moon_raw.h"
using namespace std;

moon_raw::moon_raw(ifstream& file) {
	double Tempary;
	char* temp = new char[100];
	//��������� ������ ��� �������� � ����� moon_raw
	file >> data >> time >> Tempary >> Tempary >> el >> az;
	file.getline(temp, 100, '\n');
}
