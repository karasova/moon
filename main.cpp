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

	//считываем заголовок и забываем про него  
	char header[10];
	ifstream file("2018.dat");	
	file.getline(header, 100, '\n');	

	//считываем данные в вектор, используя созданный класс moon_raw
	cout << "Загрузка, подождите..." << endl;
	while (file) {
		moon_raw* temp = new moon_raw(file);
		mraw.push_back(*temp);
	}
	file.close();

	int day = 0, mounth = 0, year = 0;	
	string pass = "";

	//запускаем бесконечный цикл, выходом из которого будет являться слово exit
	while (true) {
		cout << "Введите дату в формате ДД/ММ/ГГГГ. Для выхода из программы введите exit" <<endl;
		cin >> pass;
		if (pass == "exit")
			break;
		//проверяем корректность вводимых данных
		if (pass.length() != 10 || pass[2] != '/' || pass[5] != '/') {
			cout << "Дата введена неправильно" << endl;
			continue;
		}		
		day = 10 * (pass[0] - '0') + (pass[1] - '0');
		mounth = 10 * (pass[3] - '0') + (pass[4] - '0');
		year = 1000 * (pass[6] - '0') + 100 * (pass[7] - '0') + 10 * (pass[8] - '0') + (pass[9] - '0');
		if (day > 31 || day < 0 || mounth > 12 || mounth < 0 || year < 0) {
			cout << "Дата введена неправильно" << endl;
			continue;
		}
		//запускаем функцию поиска нужных нам величин
		search(mraw, mraw.size(), pass);		
	}
	system ("pause");
	return 0;
}
