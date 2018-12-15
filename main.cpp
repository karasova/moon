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

	//ñ÷èòûâàåì çàãîëîâîê è çàáûâàåì ïðî íåãî 
	char header[10];
	ifstream file("2018.dat");	
	file.getline(header, 100, '\n');	

	//ñ÷èòûâàåì äàííûå â âåêòîð, èñïîëüçóÿ ñîçäàííûé êëàññ moon_raw
	cout << "Çàãðóçêà, ïîäîæäèòå..." << endl;
	while (file) {
		moon_raw* temp = new moon_raw(file);
		mraw.push_back(*temp);
	}
	file.close();

	int day = 0, mounth = 0, year = 0;	
	string pass = "";

	//çàïóñêàåì áåñêîíå÷íûé öèêë, âûõîäîì èç êîòîðîãî áóäåò ÿâëÿòüñÿ ñëîâî exit
	while (true) {
		cout << "Ââåäèòå äàòó â ôîðìàòå ÄÄ/ÌÌ/ÃÃÃÃ. Äëÿ âûõîäà èç ïðîãðàììû ââåäèòå exit"<<endl;
		cin >> pass;
		if (pass == "exit")
			break;
		//ïðîâåðÿåì êîððåêòíîñòü ââîäèìûõ äàííûõ
		if (pass.length() != 10 || pass[2] != '/' || pass[5] != '/') {
			cout << "Äàòà ââåäåíà íåïðàâèëüíî" << endl;
			continue;
		}		
		day = 10 * (pass[0] - '0') + (pass[1] - '0');
		mounth = 10 * (pass[3] - '0') + (pass[4] - '0');
		year = 1000 * (pass[6] - '0') + 100 * (pass[7] - '0') + 10 * (pass[8] - '0') + (pass[9] - '0');
		if (day > 31 || day < 0 || mounth > 12 || mounth < 0 || year < 0) {
			cout << "Äàòà ââåäåíà íåïðàâèëüíî" << endl;
			continue;
		}
		//çàïóñêàåì ôóíêöèþ ïîèñêà íóæíûõ íàì âåëè÷èí
		search(mraw, mraw.size(), pass);		
	}
	system ("pause");
	return 0;
}
