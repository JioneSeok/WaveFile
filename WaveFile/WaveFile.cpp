#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	char header[44];
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) {
		return 666;
	}
	xx.read(header, 44 * sizeof(char));
	xx.close();

}
