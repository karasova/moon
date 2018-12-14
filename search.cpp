#include <iostream>
#include "moon_raw.h"
#include "search.h"
#include <string>

void search (vector <moon_raw> mraw, int size, string pass) {
	double max = 0;
	double rise = 1, set = -1;
	int j = 0;
	bool set_check = false, rise_check = true;
	//запускаем цикл до конца вектора
	for (int i = 0; i < size; i++) {
		//проверяем равенство вводимой даты и текущей
		if (mraw.at(i).data[4] == pass[3] && mraw.at(i).data[5] == pass[4] && mraw.at(i).data[6] == pass[0] && mraw.at(i).data[7] == pass[1]){
			//запускаем цикл, который выполняется, пока соблюдается данное равенство
			while (mraw.at(i).data[4] == pass[3] && mraw.at(i).data[5] == pass[4] && mraw.at(i).data[6] == pass[0] && mraw.at(i).data[7] == pass[1]) {
				//ищем максимум по elevation для данного дня
				if (mraw.at(i).el > max) {
					max = mraw.at(i).el;
					j = i;
				}
				//ищем время восхода
				if (mraw.at(i).el > 0 && rise < 0) {
					rise = mraw.at(i).el;
					rise_check = true;
					cout << "Восход: " << mraw.at(i).time[0] << mraw.at(i).time[1] << ":" << mraw.at(i).time[2] << mraw.at(i).time[3] << ":" << mraw.at(i).time[4] << mraw.at(i).time[5] << endl;
				}
				else
					rise = mraw.at(i).el;

				//ищем время заката
				if (mraw.at(i).el < 0 && set > 0) {
					set = mraw.at(i).el;
					set_check = true;
					cout << "Закат: " << mraw.at(i).time[0] << mraw.at(i).time[1] << ":" << mraw.at(i).time[2] << mraw.at(i).time[3] << ":" << mraw.at(i).time[4] << mraw.at(i).time[5] << endl;
				}
				else
					set = mraw.at(i).el;
				//переходим на следующую минуту данного дня 
				i++;
			}
			//проверяем, нашлось ли время восхода или заката, если нет, выводим соответствующее сообщение
			if (rise_check == false)
				cout << "В данный день не наблюдается восхода луны" << endl;
			if (set_check == false)
				cout << "В данный день не наблюдается заката луны" << endl;
			//прерываем цикл (так как нужная дата уже нашлась — дальше проверять нет смысла)
			break;
		}		
	}
	//выводим время кульминации для данного дня 
	if (j != 0)
		cout << "Кульминация: " << mraw.at(j).time[0] << mraw.at(j).time[1] << ":" << mraw.at(j).time[2] << mraw.at(j).time[3] << ":" << mraw.at(j).time[4] << mraw.at(j).time[5] << endl;
}