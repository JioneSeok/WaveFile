#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char header[44];
	int* samplerate, * byteRate; //samplerate = fs, byteRate = b
	short* NumChannels, * bitsperS; //NumChannels = 

	ifstream musicfile;
	musicfile.open("musicfile.wav", ios::binary | ios::in);
	if (!musicfile) return 77;
	musicfile.read(header, sizeof(header));
	musicfile.close();

	NumChannels = (short*)(header + 22);
	cout << *NumChannels << endl;
	*NumChannels = 1;
	cout << *NumChannels << endl;

	samplerate = (int*)(header + 24);
	cout << *samplerate << endl;

	byteRate = (int*)(header + 28);
	cout << *byteRate << endl;
	*byteRate = NumChannels[0] * samplerate[0] * sizeof(short);
	cout << *byteRate << endl;

	bitsperS = (short*)(header + 34);
	cout << *bitsperS << endl;

	int N = samplerate[0] * 10;
	short* data;
	data = new short[N];

	musicfile.open("musicfile.wav", ios::binary | ios::in);
	musicfile.read((char*)data, N * sizeof(short));
	musicfile.close();
	//Sprint 1,2


	ofstream xx;
	xx.open("my.wav", ios::binary | ios::out);
	if (!xx) return 888;
	xx.write(header, sizeof(header));
	xx.write((char*)data, N * sizeof(short));
	xx.close();

	//Sprint 3
	short* data1;
	data1 = new short[samplerate[0]];

	const float pi = 3.141492;
	float dt = 1. / samplerate[0];
	float a = 10000.0;
	float f = 440.0;

	for (int i = 0; i < samplerate[0]; i++) {
		data1[i] = (short)(a * sin(2.0 * pi * f * i * dt));
	}

	xx.open("my.wav", ios::binary | ios::out);
	if (!xx) {
		return 666;
	}
	xx.write((char*)header, 44 * sizeof(char));
	xx.write((char*)data1, 44100 * sizeof(short));
	xx.close();

	//Sprint 4



}