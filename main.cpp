#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>
#include "moon_raw.h"
#include <vector>
#include "search.h"
#include <cstdlib>

using namespace std;
vector <moon_raw> mraw;

int main() {
	setlocale(LC_ALL, "Russian");

	//��������� ��������� � �������� ��� ���� 
	char header[10];
	ifstream file("2018.dat");	
	file.getline(header, 100, '\n');	

	//��������� ������ � ������, ��������� ��������� ����� moon_raw
	cout << "��������, ���������..." << endl;
	while (file) {
		moon_raw* temp = new moon_raw(file);
		mraw.push_back(*temp);
	}

	int day = 0, mounth = 0, year = 0;	
	string pass = "";

	//��������� ����������� ����, ������� �� �������� ����� �������� ����� exit
	while (true) {
		cout << "������� ���� � ������� ��/��/����. ��� ������ �� ��������� ������� exit"<<endl;
		cin >> pass;
		if (pass == "exit")
			break;
		//��������� ������������ �������� ������
		if (pass.length() != 10 || pass[2] != '/' || pass[5] != '/') {
			cout << "���� ������� �����������" << endl;
			continue;
		}		
		day = 10 * (pass[0] - '0') + (pass[1] - '0');
		mounth = 10 * (pass[3] - '0') + (pass[4] - '0');
		year = 1000 * (pass[6] - '0') + 100 * (pass[7] - '0') + 10 * (pass[8] - '0') + (pass[9] - '0');
		if (day > 31 || day < 0 || mounth > 12 || mounth < 0 || year < 0) {
			cout << "���� ������� �����������" << endl;
			continue;
		}
		//��������� ������� ������ ������ ��� �������
		search(mraw, mraw.size(), pass);		
	}
	system ("pause");
	return 0;
}
