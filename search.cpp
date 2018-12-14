#include <iostream>
#include "moon_raw.h"
#include "search.h"
#include <string>

void search (vector <moon_raw> mraw, int size, string pass) {
	double max = 0;
	double rise = 1, set = -1;
	int j = 0;
	bool set_check = false, rise_check = true;
	//��������� ���� �� ����� �������
	for (int i = 0; i < size; i++) {
		//��������� ��������� �������� ���� � �������
		if (mraw.at(i).data[4] == pass[3] && mraw.at(i).data[5] == pass[4] && mraw.at(i).data[6] == pass[0] && mraw.at(i).data[7] == pass[1]){
			//��������� ����, ������� �����������, ���� ����������� ������ ���������
			while (mraw.at(i).data[4] == pass[3] && mraw.at(i).data[5] == pass[4] && mraw.at(i).data[6] == pass[0] && mraw.at(i).data[7] == pass[1]) {
				//���� �������� �� elevation ��� ������� ���
				if (mraw.at(i).el > max) {
					max = mraw.at(i).el;
					j = i;
				}
				//���� ����� �������
				if (mraw.at(i).el > 0 && rise < 0) {
					rise = mraw.at(i).el;
					rise_check = true;
					cout << "������: " << mraw.at(i).time[0] << mraw.at(i).time[1] << ":" << mraw.at(i).time[2] << mraw.at(i).time[3] << ":" << mraw.at(i).time[4] << mraw.at(i).time[5] << endl;
				}
				else
					rise = mraw.at(i).el;

				//���� ����� ������
				if (mraw.at(i).el < 0 && set > 0) {
					set = mraw.at(i).el;
					set_check = true;
					cout << "�����: " << mraw.at(i).time[0] << mraw.at(i).time[1] << ":" << mraw.at(i).time[2] << mraw.at(i).time[3] << ":" << mraw.at(i).time[4] << mraw.at(i).time[5] << endl;
				}
				else
					set = mraw.at(i).el;
				//��������� �� ��������� ������ ������� ��� 
				i++;
			}
			//���������, ������� �� ����� ������� ��� ������, ���� ���, ������� ��������������� ���������
			if (rise_check == false)
				cout << "� ������ ���� �� ����������� ������� ����" << endl;
			if (set_check == false)
				cout << "� ������ ���� �� ����������� ������ ����" << endl;
			//��������� ���� (��� ��� ������ ���� ��� ������� � ������ ��������� ��� ������)
			break;
		}		
	}
	//������� ����� ����������� ��� ������� ��� 
	if (j != 0)
		cout << "�����������: " << mraw.at(j).time[0] << mraw.at(j).time[1] << ":" << mraw.at(j).time[2] << mraw.at(j).time[3] << ":" << mraw.at(j).time[4] << mraw.at(j).time[5] << endl;
}