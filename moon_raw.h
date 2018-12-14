#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class moon_raw {
public:
	char* data = new char[8];
	char* time = new char[6];
	double el, az;
	moon_raw(ifstream& file);
};