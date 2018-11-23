#include <iostream>
#include <fstream>

using namespace std;

int main () {
	ifstream fin1{"ciphertext1"};
	ifstream fin2{"ciphertext2"};
	ofstream fout{"xor"};
	char c1, c2;
	for (int i = 0; i < 300; i++) {
		fin1 >> c1;
		fin2 >> c2;
		fout << (char)((c1 | c2) - (c1 & c2));
	}
	return 0;
}
