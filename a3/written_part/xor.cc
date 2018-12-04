#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char * argv []) {
	ifstream fin1{argv[1]};
	ifstream fin2{argv[2]};
	ofstream fout{argv[3]};
	char c1, c2;
	for (int i = 0; i < 300; i++) {
		fin1 >> noskipws >> c1;
		fin2 >> noskipws >> c2;
		fout << (char)((c1 | c2) - (c1 & c2));
	}
	return 0;
}
