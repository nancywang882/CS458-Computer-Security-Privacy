#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main () {
	ifstream fin {"article"};
	ofstream fout {"dictionary"};
	set<string>words;
	string word;
	while (fin >> word) {
		words.insert(word);
	}
	for (auto w : words) {
		fout << w << endl;
	}
	return 0;
}
