#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


bool cmp (pair<string, int> p1, pair<string,int> p2) { return (get<1>(p1) < get<1>(p2)); }

vector<vector<pair<string, int>>> file2vector(string fname) {
	vector<vector<pair<string, int>>> table;
	ifstream fin{fname};
	string line;
	vector<map<string, int>> temp;
	while (getline(fin, line)) {
		istringstream iss {line};
		string word;
		for (int i = 0; getline(iss, word, ','); i++) {
			if (temp.size() == i) temp.push_back({});
			if (temp[i].find(word) != temp[i].end()) {
				temp[i][word] += 1;
			} else {
				temp[i][word] = 1;
			}
		}
	}

	for (map<string, int> column : temp) {
		vector<pair<string, int>> v;
		for (auto &e : column) {
			pair <string, int> p (e.first,e.second);
			v.push_back(p);
		}
		sort(v.begin(), v.end(), cmp);
		table.push_back(v);
	}
	return table;
}
int main(int argc, char* argv[]) {
	vector<vector<pair<string, int>>> background = file2vector(argv[1]);
	vector<vector<pair<string, int>>> encrypted = file2vector(argv[2]);
	ofstream fout {argv[3]};
	for (int i = 0; i < background.size(); i++) {
		for (int j = 0; j < background[i].size(); j++) {
			fout << get<0>(encrypted[i][j]) << "," << get<0>(background[i][j]) << endl;
		}
	}
	return 0;
}
